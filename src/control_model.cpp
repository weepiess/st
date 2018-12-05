////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Model Code for robot
///ALL RIGHTS RESERVED
///@file:control_model.cpp
///@brief: robot 控制模型，包含对所有应用的管理，创建应用，并改变应用，以及监听操作手
/// 的指令，并处理。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-9-4
///修订历史：
////////////////////////////////////////////////////////////////////////////////
#include "image_tool.h"
#include "control_model.h"
#include "basic_tool.h"
#include "serial_port_debug.h"

ControlModel::ControlModel(){}

ControlModel::~ControlModel(){
    delete mBehaviorTree;
}

void ControlModel::init(RobotModel* robotModel){
    pRobotModel=robotModel;

    //auto blackboard_ptr = std::make_shared<SentryBlackboard>(mSentryBlackboard);
    mBehaviorTree = new BehaviorTreeTest(mSentryBlackboard, 25);

    mSetMode=ROBOT_MODE_AUTO;
}

//串口数据接收处理入口
void ControlModel::serialListenDataProcess(SerialPacket recvPacket) {
//复杂自定义数据包，需要自定义解析单独处理
    //debug
    //SerialPortDebug::testSerialPortListenPrint(recvPacket);
    unsigned char CMD = recvPacket.getCMD();
    // cout<<"CMD:"<<(int)CMD<<endl;
    if(CMD_SERIAL_BLOOD_INFO_RECV == CMD){
        mSentryBlackboard->updateBloodInfo(recvPacket.getIntInBuffer(2), recvPacket.getIntInBuffer(6),
            recvPacket.getUncharInBuffer(10), recvPacket.getUncharInBuffer(11));
    } else if(CMD_SERIAL_CHASSIS_INFO_RECV == CMD){
        mSentryBlackboard->updateChassisInfo(recvPacket.getFloatInBuffer(2), recvPacket.getFloatInBuffer(6),
            recvPacket.getShortIntInBuffer(10), recvPacket.getUncharInBuffer(12));
    }
}

void ControlModel::processFSM(){
    //模式切换预处理
    if(mSetMode!=pRobotModel->getCurrentMode()){
        pRobotModel->setCurrentMode(mSetMode);
        switch (mSetMode){
            case ROBOT_MODE_STOP:
                mBehaviorTree->stop();
                break;
            case ROBOT_MODE_AUTO:
                mBehaviorTree->execute();
                break;
            default:
                break;
        }
    }

    //模式运行
    switch (pRobotModel->getCurrentMode()){
        case ROBOT_MODE_STOP:
            break;
        case ROBOT_MODE_AUTO:{
            /*
            cv::Mat src;
            pRobotModel->getVisionCapture()->getImg(src);
            string s = "src";
            cv::imshow(s, src);
            cv::waitKey(1);
            */

            //从blackboard中取出数据发送给串口
            serialSendDataProcess();
            usleep(10000); //1ms
            break;
        }
        default:
            cout<<"[aiProcess]mode error"<<endl;
            break;
    }
}

void ControlModel::serialSendDataProcess(){
    if(mSentryBlackboard->getOutChassisPos()->is_update){
        pRobotModel->getpSerialInterface()->chassisPosSet(
            mSentryBlackboard->getOutChassisPos()->pos_to_move,
            mSentryBlackboard->getOutChassisPos()->move_level);
        mSentryBlackboard->getOutChassisPos()->is_update = false;
    }

    if(mSentryBlackboard->getOutChassisConstMove()->is_update){
        pRobotModel->getpSerialInterface()->chassisConstMove(
            mSentryBlackboard->getOutChassisConstMove()->move_level);
        mSentryBlackboard->getOutChassisConstMove()->is_update = false;
    }

    if(mSentryBlackboard->getOutChassisRandomMove()->is_update){
        pRobotModel->getpSerialInterface()->chassisRandomMove(
            mSentryBlackboard->getOutChassisRandomMove()->move_level,
            mSentryBlackboard->getOutChassisRandomMove()->min_pos,
            mSentryBlackboard->getOutChassisRandomMove()->max_pos);
        mSentryBlackboard->getOutChassisRandomMove()->is_update = false;
    }

    if(mSentryBlackboard->getOutChassisSwingMove()->is_update){
        pRobotModel->getpSerialInterface()->chassisSwingMove(
            mSentryBlackboard->getOutChassisSwingMove()->move_level);
        mSentryBlackboard->getOutChassisSwingMove()->is_update = false;
    }

    if(mSentryBlackboard->getOutShoot()->is_update){
        pRobotModel->getpSerialInterface()->shoot(
            mSentryBlackboard->getOutShoot()->bullet_count);
        mSentryBlackboard->getOutShoot()->is_update = false;
    }

    if(mSentryBlackboard->getOutGlobalScan()->is_update){
        pRobotModel->getpSerialInterface()->globalScanning(
            mSentryBlackboard->getOutGlobalScan()->pitch_move_level,
            mSentryBlackboard->getOutGlobalScan()->yaw_move_level);
        mSentryBlackboard->getOutGlobalScan()->is_update = false;
    }

    if(mSentryBlackboard->getOutLocalScan()->is_update){
        pRobotModel->getpSerialInterface()->localScanning(
            mSentryBlackboard->getOutLocalScan()->yaw,
            mSentryBlackboard->getOutLocalScan()->pitch_move_level,
            mSentryBlackboard->getOutLocalScan()->yaw_move_level);
        mSentryBlackboard->getOutLocalScan()->is_update = false;
    }

    if(mSentryBlackboard->getOutRelativeAngle()->is_update){
        pRobotModel->getpSerialInterface()->yuntaiRelativeControl(
            mSentryBlackboard->getOutRelativeAngle()->pitch,
            mSentryBlackboard->getOutRelativeAngle()->yaw,
            mSentryBlackboard->getOutRelativeAngle()->speed_signal);
        mSentryBlackboard->getOutRelativeAngle()->is_update = false;
    }
}