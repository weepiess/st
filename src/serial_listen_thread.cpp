#include "serial_listen_thread.h"

SerialListenThread::SerialListenThread(){}

SerialListenThread::~SerialListenThread(){}

SerialListenThread::init(Blackboard::Ptr blackboard_ptr_){
    blackboard_ptr = blackboard_ptr_;
}

SerialListenThread::run(){
    SerialPacket recvPacket;
    while(!isInterrupt()){
        //是否需要考虑对监听数据构造队列，因为处理数据函数需要一定时间。
        if(blackboard_ptr->getSerialInterface()->dataRecv(recvPacket)==0){
            //更新blackboard中的数据
            
        }

    }

}