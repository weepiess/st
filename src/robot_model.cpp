////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Model Code for robot
///ALL RIGHTS RESERVED
///@file:robot_model.cpp
///@brief: 机器人数据资源模型，包含机器人的所有硬件资源的统一管理，
/// 以及状态数据的统一管理，并提供机器人控制基本接口。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-9-4
///修订历史：
////////////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <robot_model.h>
#include <basic_tool.h>

using namespace cv;
using namespace std;

RobotModel::RobotModel() {

}
RobotModel::~RobotModel() {

}

int RobotModel::init(){
    string serialPath,videoPath;
    bool isUseCameraSdk;

    //配置文件
    cv::FileStorage f("../res/main_config.yaml", cv::FileStorage::READ);
    f["robot_id"] >> mRobotId;//机器人id
    f["enemy_is_red"] >> mIsEnemyRed;//敌方颜色
    f["use_camera_sdk"] >> isUseCameraSdk;
    f["serial_path"] >> serialPath;//机器人串口路径
    f["capture_path"] >> videoPath;//机器人摄像头路径
    f.release();
    
    //初始化串口
    if(mSerialInterface.init(serialPath)==0) {
        cout<<"[robot model init ]: RobotSerialInterface init successed!"<<endl;
        //mSerialPort.ShowParam();
    } else{
        cout<<"[robot model init ]: RobotSerialInterface init failed!"<<endl;
    }

    //初始化摄像头
    if(isUseCameraSdk){
        if(mVisionCapture.init()==0 && mVisionCapture.startPlay(mIsEnemyRed)==0){
            cout << "[robot model init ]:VisionCapture init successed!" <<endl;
            usleep(1000000);
        } else {
            cout << "[robot model init ]:VisionCapture init failed!" <<endl;
        }
    } else {
        if(mUsbCapture.init(videoPath,1280,720)==0){
            cout << "[robot model init ]:UsbCapture init successed!" <<endl;
            usleep(1000000);//等待1s
            //mUsbCapture.infoPrint();
        }else{
            cout << "[robot model init ]:UsbCapture init failed!" <<endl;
        }
    }
    
    mCurrentMode=ROBOT_MODE_STOP;
}


unsigned char RobotModel::getRobotId(){
    return mRobotId;
};

bool RobotModel::isEnemyRed(){
    return mIsEnemyRed;
}

UsbCaptureWithThread* RobotModel::getpUsbCapture() {
    return &mUsbCapture;
}

SerialInterface* RobotModel::getpSerialInterface() {
    return &mSerialInterface;
}

MindVision* RobotModel::getVisionCapture(){
    return &mVisionCapture;
}

void RobotModel::setCurrentMode(RobotMode robotMode) {
    mCurrentMode=robotMode;
}

RobotMode RobotModel::getCurrentMode() {
    return mCurrentMode;
}

void RobotModel::mcuDataUpdate(float pitch, float yaw){
    pthread_mutex_lock(&dataMutex);//加锁
    mCurrentPitch=pitch;
    mCurrentYaw=yaw;
    pthread_mutex_unlock(&dataMutex);
}

float RobotModel::getCurrentPitch() {
    float tmp;
    pthread_mutex_lock(&dataMutex);//加锁
    tmp=mCurrentPitch;
    pthread_mutex_unlock(&dataMutex);
    return tmp;
}

float RobotModel::getCurrentYaw() {
    float tmp;
    pthread_mutex_lock(&dataMutex);//加锁
    tmp=mCurrentYaw;
    pthread_mutex_unlock(&dataMutex);
    return tmp;
}