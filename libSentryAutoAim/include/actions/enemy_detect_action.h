#ifndef SENTRY_ENEMY_DETECT_ACTION
#define SENTRY_ENEMY_DETECT_ACTION

#include "action_node.h"

#include "log.h"
#include "base_aim.h"

using namespace bt;

struct SentryParams{
    //图像信息
    bool is_enemy_red;
    //图像阈值
    int substract_thresh;
    //图像宽高
    cv::Size image_size;

    //灯条筛选信息
    int max_allow_angle; //最大偏角
    float max_hw_ratio; //最大高宽之比
    float min_hw_ratio; //最小高宽之比
    
    //装甲板匹配信息
    int max_diff_angle; //最大角度差
    float max_yx_diff_ratio; //最大yx之比
    float max_height_ratio; //最大高度比
    float max_dis_height_ratio; //最大距离与高度之比
    float min_dis_height_ratio; //最小距离与高度之比
};

//图像预处理节点，只做简单处理，不区分装甲板
class EnemyDetectAction: public ActionNode, public BaseAim{
public:
    EnemyDetectAction(const Blackboard::Ptr & blackboard_ptr_);
    virtual ~EnemyDetectAction() noexcept = default;

protected:
    virtual void onInitialize();
    virtual BehaviorState update();
    virtual void onTerminate(BehaviorState state);

    //初始化参数
    void initParams();
    //处理图像
    bool setImage();
    //根据处理后的图像找灯条
    void findLightBars(vector<cv::RotatedRect> &pre_armor_lamps);
    //根据灯条匹配装甲板
    bool matchLightBars(vector<cv::RotatedRect> &detected_armor_lamps);
    //解决丢帧
    bt::BehaviorState handleLostFrames();

private:
    //处理后的图像
    cv::Mat mask;
    //图像信息
    SentryParams params;
    //丢失的帧数
    int lost_frames;
};

#endif //SENTRY_ENEMY_DETECT_ACTION