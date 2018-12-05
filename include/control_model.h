////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Model Code for robot
///ALL RIGHTS RESERVED
///@file:control_model.h
///@brief: robot 控制模型，包含对所有应用的管理，创建应用，并改变应用，以及监听操作手的指令
///，并处理。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-9-4
///修订历史：
////////////////////////////////////////////////////////////////////////////////


#ifndef RMDEMO_CONTROL_MODEL_H
#define RMDEMO_CONTROL_MODEL_H
#include "robot_model.h"
#include <opencv2/opencv.hpp>
#include "blackboard.h"
#include "mind_vision.h"
#include "decision.h"
using namespace bt;
class ControlModel{
public:
    ControlModel();
    ~ControlModel();

public:
    void init(RobotModel* pRobotModel);
    //串口监听数据处理函数接口
    void serialListenDataProcess(SerialPacket recvPacket);
    void processFSM();
    void serialSendDataProcess();

private:
    //临时变量，记录上次的状态
    RobotMode mSetMode;
    RobotModel* pRobotModel;
    int hCamera;
    MindVision mVision;
    bool mEnemyIsRed;
    Blackboard::Ptr mBlackboard = std::make_shared<Blackboard>();
    Decision* mBehaviorTree;
};

#endif //RMDEMO_CONTROL_MODEL_H
