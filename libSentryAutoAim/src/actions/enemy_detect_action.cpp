#include "enemy_detect_action.h"
#include "chrono"

EnemyDetectAction::EnemyDetectAction(const Blackboard::Ptr& blackboard_ptr)
        :ActionNode::ActionNode("enemy_detect_action", blackboard_ptr){
    initParams();
    lost_frames = 60;
}

void EnemyDetectAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}

bt::BehaviorState EnemyDetectAction::update(){
    if(!setImage()){
        return handleLostFrames();
    }
    vector<cv::RotatedRect> lamps;
    findLightBars(lamps);
    if(!matchLightBars(lamps)){
        return handleLostFrames();
    }
    lost_frames = 0; //找到装甲板之后则丢帧数重置
    blackboard_ptr_->getArmorDetectInfo()->is_found = true;
    return BehaviorState::SUCCESS;
}

void EnemyDetectAction::onTerminate(bt::BehaviorState state){
    switch (state){
      case BehaviorState::IDLE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" IDLE!";
        break;
      case BehaviorState::SUCCESS:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" find armor!";
        break;
      case BehaviorState::FAILURE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" lost frames!";
        break;
      default:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" ERROR!";
        return;
    }
}

bt::BehaviorState EnemyDetectAction::handleLostFrames(){
    ++lost_frames;
    blackboard_ptr_->getArmorDetectInfo()->is_found = false;
    if(lost_frames < 60){ //丢帧在60帧以内，随着丢帧数的增加不断增加swing的速度等级，同时云台小幅度局部扫描
        //blackboard_ptr_->chassisSwingMove(40);
        //blackboard_ptr_->localScanning(blackboard_ptr_->getCurrYaw(), 30, 30);
        return BehaviorState::RUNNING;
    }
    return BehaviorState::FAILURE; //60帧以上则返回检测失败
}

bool EnemyDetectAction::setImage(){ //1-3ms
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    cv::Mat src;
    if(blackboard_ptr_->getVisionCapture()->getImg(src) != 0)
        return false;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    LOG_ERROR<<duration.count();
    //imshow("src", src);

    cv::Mat channels[3];
    split(src, channels);
    if(blackboard_ptr_->isEnemyRed()){
        LOG_INFO<<"haha";
        GaussianBlur(channels[2] - channels[1], mask, Size(5,5), 0);
    } else{
        GaussianBlur(channels[0] - channels[2], mask, Size(5,5), 0);
    }
    threshold(mask, mask, params.substract_thresh, 255, THRESH_BINARY);
    //膨胀
    cv::Mat element = getStructuringElement(MORPH_ELLIPSE, Size(1, 3));
    dilate(mask, mask, element);
    //cv::imshow("mask", mask);
    //waitKey(1);

    return true;
}

//寻找灯管
void EnemyDetectAction::findLightBars(vector<cv::RotatedRect> &detected_armor_lamps){ //0ms
    vector<vector<Point> > contours;
    vector<Vec4i> hierarcy;
    //寻找轮廓，将满足条件的轮廓放入待确定的数组中去
    findContours(mask, contours, hierarcy, CV_RETR_EXTERNAL, CHAIN_APPROX_NONE, Size(0,0));

    cv::RotatedRect temp;
    //防止被敌方激光瞄到镜头，红光一下太多程序崩溃
    if(contours.size() > 50) return;
    for(int i=0; i<contours.size(); i++){
        if(contours[i].size() > 10){
            //椭圆拟合相比与minAreaRect，对水波纹的响应不明显，角度差不会有明显的跳动
            temp = fitEllipse(contours[i]);//寻找椭圆拟合外接矩形
            //椭圆拟合纠正角度
            adjustEllipseAngle(temp);
            //筛选出一定不是灯条的矩形
            if(abs(temp.angle) > params.max_allow_angle) continue; //最大偏角限制
            float hw_ratio = temp.size.height/temp.size.width;
            if(hw_ratio > params.max_hw_ratio || hw_ratio < params.min_hw_ratio) continue; //宽高比例限制
            if(temp.size.area() > 10000 || temp.size.area() < 10) continue; //过大或者过小限制
            detected_armor_lamps.push_back(temp);
        }
    }
}

//匹配灯管
bool EnemyDetectAction::matchLightBars(vector<cv::RotatedRect> &detected_armor_lamps){ //0ms
    //灯条太少或者太多都放弃，太多容易误识别
    if(detected_armor_lamps.size()<=1 || detected_armor_lamps.size()>=20) return false;

    //权重，越不利的因素应该越大，角度差越大越不可能匹配，高度比例越大也越不可能，内角越小越不可能，所以内角采用90度减去当前内角
    int angle_diff_weight = 5;
    int height_ratio_weight = 2;
    int yx_ratio_weight = 3;

    //初始化
    int size = detected_armor_lamps.size();
    vector<float> diff(size, 0x3f3f3f3f);
    vector<float> best_match_index(size, -1);
    
    for(int i=0; i<detected_armor_lamps.size(); i++){
        cout<<detected_armor_lamps.at(i).angle<<" "<<detected_armor_lamps.at(i).size.height<<" "<<detected_armor_lamps.at(i).size.width<<" ---- ";
    }
    cout<<endl;

    //与灯管花费计算有关的变量
    float diff_angle, height_ratio, yx_ratio, dis_height_ratio, totalDiff, dist, avg_height;
    int i,j;
    
    //精细化处理灯条，生成最后的匹配对
    for(i=0; i<size; i++){
        int currIndex = -1;
        const cv::RotatedRect &current = detected_armor_lamps.at(i);

        for(j=i+1; j<size; j++){
            const cv::RotatedRect &compare = detected_armor_lamps.at(j);

            //灯条角度差超过设定角度忽略
            diff_angle = abs(compare.angle - current.angle);
            if(diff_angle > params.max_allow_angle) continue;
            //LOG_INFO<<"diff_angle";

            //y差值与x差值超过设定值忽略
            if(current.center.x - compare.center.x == 0) yx_ratio=100;
            else yx_ratio = abs(current.center.y-compare.center.y)/abs(current.center.x-compare.center.x);
            if(yx_ratio > params.max_yx_diff_ratio) continue;
            //LOG_INFO<<"inside_angle";
            
            //两灯条高度比例不在范围内则忽略
            if(compare.size.height > current.size.height)
                height_ratio = compare.size.height*1.0f/current.size.height;
            else
                height_ratio = current.size.height*1.0f/compare.size.height;
            //LOG_INFO<<height_ratio;
            if(height_ratio > params.max_height_ratio) continue;
            //LOG_INFO<<"height_ratio";

            //灯条之间的距离与灯条的平均长度之比需要在一定范围之内
            dist = BasicTool::calc2PointApproDistance(compare.center, current.center);
            avg_height = (compare.size.height + current.size.height) / 2;
            dis_height_ratio = dist / avg_height;
            //LOG_INFO<<dis_height_ratio;
            if(dis_height_ratio > params.max_dis_height_ratio || dis_height_ratio < params.min_dis_height_ratio) continue;
            
            //角度差约束会在几度之内，高度比例约束会在1到1.x之内，内角约束大致在几十度到90度(目前70-90)，
            //实际上用90度减去角度应该在0-几十度之内，且越小越好
            //用归一化的值算最后的花费，避免不同值的取值范围不同
            totalDiff = angle_diff_weight * (diff_angle/params.max_allow_angle) //角度花费
                        + height_ratio_weight * ((height_ratio-1)/(params.max_height_ratio-1)) //高度比例花费
                        + yx_ratio_weight * (yx_ratio/params.max_yx_diff_ratio); //内角花费

            //更新j代表的灯条的最小花费
            if(diff.at(j) > totalDiff)
                diff.at(j) = totalDiff;

            //更新i代表的当前灯条的最优匹配
            if(diff.at(i) > totalDiff){
                diff.at(i) = totalDiff;
                currIndex = j;
            }
        }

        //一对灯管肯定花费是最少的，所以如果当前花费比两个的花费都要少，就记录是最优
        if(currIndex==-1) continue;
        else {
            best_match_index.at(i) = currIndex;
            best_match_index.at(currIndex) = i;
        }
    }

    std::vector<Armor>& detected_armor_ = blackboard_ptr_->getArmorDetectInfo()->detected_armor;
    //清除装甲板的size
    detected_armor_.clear();
    //如果capacity大于5，则重新分配为5
    if(detected_armor_.capacity() > 5)
        detected_armor_.reserve(5);
    bool is_found = false;
    for(i=0; i<size; i++){
        int index = best_match_index.at(i);
        if(index == -1 || index <= i) continue;
        if(i == best_match_index.at(index)){
            is_found = true;
            //emplace_back直接调用构造函数，省去了移动或者拷贝构造函数的时间
            detected_armor_.emplace_back(detected_armor_lamps.at(i), detected_armor_lamps.at(index));
        }
    }
    return is_found;
}

void EnemyDetectAction::initParams(){
    //初始化总体参数
    cv::FileStorage paramsFile("../libSentryAutoAim/res/infantry_config.yaml", cv::FileStorage::READ);
    params.is_enemy_red = blackboard_ptr_->isEnemyRed();
    if(params.is_enemy_red){
        paramsFile["red_sbstract_thresh"] >> params.substract_thresh;
    } else {
        paramsFile["blue_sbstract_thresh"] >> params.substract_thresh;
    }
    //灯条信息
    paramsFile["max_allow_angle"] >> params.max_allow_angle;
    paramsFile["max_hw_ratio"] >> params.max_hw_ratio;
    paramsFile["min_hw_ratio"] >> params.min_hw_ratio;
    //装甲板信息
    paramsFile["max_diff_angle"] >> params.max_diff_angle;
    paramsFile["max_yx_diff_ratio"] >> params.max_yx_diff_ratio;
    paramsFile["max_height_ratio"] >> params.max_height_ratio;
    paramsFile["max_dis_height_ratio"] >> params.max_dis_height_ratio;
    paramsFile["min_dis_height_ratio"] >> params.min_dis_height_ratio;
    paramsFile["img_width"] >> params.image_size.width;
    paramsFile["img_height"] >> params.image_size.height;
    paramsFile.release();

    //读入相机参数
    cv::FileStorage cameraFile("../libSentryAutoAim/res/camera_params.yaml", cv::FileStorage::READ);
    float fx, fy, cx, cy, rdx, rdy, tdx, tdy;
    cameraFile["fx"] >> fx;
    cameraFile["fy"] >> fy;
    cameraFile["cx"] >> cx;
    cameraFile["cy"] >> cy;
    cameraFile["rdx"] >> rdx;
    cameraFile["rdy"] >> rdy;
    cameraFile["tdx"] >> tdx;
    cameraFile["tdy"] >> tdy;

    pnp_solver.setCameraMatrix(fx, fy, cx, cy);
    pnp_solver.setDistortionCoef(rdx, rdy, tdx, tdy);
    cameraFile.release();
}