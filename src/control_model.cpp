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
    mBehaviorTree = new Decision(mBlackboard, 25);
    pRobotModel=robotModel;
    mSetMode=ROBOT_MODE_AUTO;
    pRobotModel->getVisionCapture()->init();
    pRobotModel->getVisionCapture()->startPlay(pRobotModel->isEnemyRed());
}

//串口数据接收处理入口
void ControlModel::serialListenDataProcess(SerialPacket recvPacket) {
//复杂自定义数据包，需要自定义解析单独处理
    //debug
    //SerialPortDebug::testSerialPortListenPrint(recvPacket);
    Mat src;
    unsigned char CMD = recvPacket.getCMD();
    // cout<<"CMD:"<<(int)CMD<<endl;
    if(CMD_SERIAL_BLOOD_INFO_RECV == CMD){
        mBlackboard->updateBloodInfo(recvPacket.getIntInBuffer(2), recvPacket.getIntInBuffer(6),
            recvPacket.getUncharInBuffer(10), recvPacket.getUncharInBuffer(11));
    } else if(CMD_SERIAL_CHASSIS_INFO_RECV == CMD){
        mBlackboard->updateChassisInfo(recvPacket.getFloatInBuffer(2), recvPacket.getFloatInBuffer(6),
            recvPacket.getShortIntInBuffer(10), recvPacket.getUncharInBuffer(12));
    }
    pRobotModel->getVisionCapture()->getImg(src);
    mBlackboard->updateImg(src);
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
    if(mBlackboard->getOutChassisPos() != NULL){
        pRobotModel->getpSerialInterface()->chassisPosSet(
            mBlackboard->getOutChassisPos()->pos_to_move,
            mBlackboard->getOutChassisPos()->move_level);
            mBlackboard->getOutChassisPos()->is_update = false;
    }

    if(mBlackboard->getOutChassisConstMove() != NULL){
        pRobotModel->getpSerialInterface()->chassisConstMove(
            mBlackboard->getOutChassisConstMove()->move_level);
            mBlackboard->getOutChassisConstMove()->is_update = false;
    }

    if(mBlackboard->getOutChassisRandomMove() != NULL){
        pRobotModel->getpSerialInterface()->chassisRandomMove(
            mBlackboard->getOutChassisRandomMove()->move_level,
            mBlackboard->getOutChassisRandomMove()->min_pos,
            mBlackboard->getOutChassisRandomMove()->max_pos);
            mBlackboard->getOutChassisRandomMove()->is_update = false;
    }

    if(mBlackboard->getOutChassisSwingMove() != NULL){
        pRobotModel->getpSerialInterface()->chassisSwingMove(
            mBlackboard->getOutChassisSwingMove()->move_level);
            mBlackboard->getOutChassisSwingMove()->is_update = false;
    }

    if(mBlackboard->getOutShoot() != NULL){
        pRobotModel->getpSerialInterface()->shoot(
            mBlackboard->getOutShoot()->bullet_count);
            mBlackboard->getOutShoot()->is_update = false;
    }

    if(mBlackboard->getOutGlobalScan() != NULL){
        pRobotModel->getpSerialInterface()->globalScanning(
            mBlackboard->getOutGlobalScan()->pitch_move_level,
            mBlackboard->getOutGlobalScan()->yaw_move_level);
            mBlackboard->getOutGlobalScan()->is_update = false;
    }

    if(mBlackboard->getOutLocalScan() != NULL){
        pRobotModel->getpSerialInterface()->localScanning(
            mBlackboard->getOutLocalScan()->yaw,
            mBlackboard->getOutLocalScan()->pitch_move_level,
            mBlackboard->getOutLocalScan()->yaw_move_level);
            mBlackboard->getOutLocalScan()->is_update = false;
    }

    if(mBlackboard->getOutRelativeAngle() != NULL){
        pRobotModel->getpSerialInterface()->yuntaiRelativeControl(
            mBlackboard->getOutRelativeAngle()->pitch,
            mBlackboard->getOutRelativeAngle()->yaw,
            mBlackboard->getOutRelativeAngle()->speed_signal);
            mBlackboard->getOutRelativeAngle()->is_update = false;
    }
}