////////////////////////////////////////////////////////////////////////////////
///Copyright(c)     UESTC ROBOMASTER2018      SerialPort Code for robot
///ALL RIGHTS RESERVED
///@file:serial_interface.cpp
///@brief: 机器人控制基本接口源文件，包含对车底盘及云台的基本接口。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-3-4
///修订历史：
////////////////////////////////////////////////////////////////////////////////
#include "serial_interface.h"

SerialInterface::SerialInterface(){}


SerialInterface::~SerialInterface() {}

int SerialInterface::init(std::string devPath){
    if(mMcuSerialPort.init(devPath)){
        return 0;
    }else{
        return -1;
    }
}

bool SerialInterface::isOpen(){
    return mMcuSerialPort.isOpen();
}

int SerialInterface::dataSend(SerialPacket sendPacket){
    if(mMcuSerialPort.Send(sendPacket.buffer,16)==16){
        return 0;
    }
    return -1;

}
int SerialInterface::dataRecv(SerialPacket &recvPacket){

    if(mMcuSerialPort.Recv(recvPacket.buffer,16)==16) {
        if(recvPacket.unPacking()==0){
            return 0;
        }
    }
    return -1;
}


/*********************控制接口**************************/
void SerialInterface::chassisStopSet(){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_CHASSIS_STOP);
    dataSend(sendPacket);
}

void SerialInterface::chassisPosSet(short int pos_move, int move_level){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_CHASSIS_POS_CONTROL);
    sendPacket.setShortIntInBuffer(pos_move,2);
    sendPacket.setIntInBuffer(move_level,4);
    dataSend(sendPacket);
}

void SerialInterface::chassisConstMove(int move_level){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_CHASSIS_CONST_MOVE);
    sendPacket.setIntInBuffer(move_level,2);
    dataSend(sendPacket);
}

void SerialInterface::chassisRandomMove(int move_level, short int min_pos, short int max_pos){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_CHASSIS_RANDOM_MOVE);
    sendPacket.setIntInBuffer(move_level,2);
    sendPacket.setShortIntInBuffer(min_pos,6);
    sendPacket.setShortIntInBuffer(max_pos,8);
    dataSend(sendPacket);
}

void SerialInterface::chassisSwingMove(int move_level){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_CHASSIS_SWING_MOVE);
    sendPacket.setIntInBuffer(move_level,2);
    dataSend(sendPacket);
}

void SerialInterface::yuntaiRelativeControl(float pitch, float yaw, unsigned char speed){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_YUNTAI_RELATIVE_ANGLE);
    sendPacket.setFloatInBuffer(pitch,2);
    sendPacket.setFloatInBuffer(yaw,6);
    sendPacket.setUncharInBuffer(speed,10);
    dataSend(sendPacket);
}

void SerialInterface::yuntaiAbsoluteControl(float pitch, float yaw, unsigned char speed){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_YUNTAI_ABSOLUTE_ANGLE);
    sendPacket.setFloatInBuffer(pitch,2);
    sendPacket.setFloatInBuffer(yaw,6);
    sendPacket.setUncharInBuffer(speed,10);
    dataSend(sendPacket);
}

void SerialInterface::shoot(unsigned char bullet_count){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_SHOOT);
    sendPacket.setUncharInBuffer(bullet_count,2);
    dataSend(sendPacket);
}

void SerialInterface::globalScanning(int pitch_move_level, int yaw_move_level){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_YUNTAI_GLOBAL_SCAN);
    sendPacket.setIntInBuffer(pitch_move_level,2);
    sendPacket.setIntInBuffer(yaw_move_level,6);
    dataSend(sendPacket);
}

void SerialInterface::localScanning(float yaw, int pitch_move_level, int yaw_move_level){
    SerialPacket sendPacket;
    sendPacket.creatPacket(CMD_SERIAL_YUNTAI_LOCAL_SCAN);
    sendPacket.setFloatInBuffer(yaw,2);
    sendPacket.setIntInBuffer(pitch_move_level,6);
    sendPacket.setIntInBuffer(yaw_move_level,10);
    dataSend(sendPacket);
}