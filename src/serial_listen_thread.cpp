#include "serial_listen_thread.h"

SerialListenThread::SerialListenThread(){}

SerialListenThread::~SerialListenThread(){}

void SerialListenThread::init(Blackboard::Ptr blackboard_ptr_){
    blackboard_ptr = blackboard_ptr_;
}

void SerialListenThread::run(){
    SerialPacket recvPacket;
    while(!isInterrupted()){
        //是否需要考虑对监听数据构造队列，因为处理数据函数需要一定时间。
        if(blackboard_ptr->getSerialInterface()->dataRecv(recvPacket)==0){
            //复杂自定义数据包，需要自定义解析单独处理
            unsigned char CMD = recvPacket.getCMD();
            // cout<<"CMD:"<<(int)CMD<<endl;
            if(CMD_SERIAL_BLOOD_INFO_RECV == CMD){
                blackboard_ptr->updateBloodInfo(recvPacket.getIntInBuffer(2), recvPacket.getIntInBuffer(6),
                    recvPacket.getUncharInBuffer(10), recvPacket.getUncharInBuffer(11));
            } else if(CMD_SERIAL_CHASSIS_INFO_RECV == CMD){
                blackboard_ptr->updateChassisInfo(recvPacket.getFloatInBuffer(2), recvPacket.getFloatInBuffer(6),
                    recvPacket.getShortIntInBuffer(10), recvPacket.getUncharInBuffer(12));
            }

        }
    }
}