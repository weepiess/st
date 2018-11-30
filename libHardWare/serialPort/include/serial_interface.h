////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      SerialPort Code for robot
///ALL RIGHTS RESERVED
///@file:serial_interface.h
///@brief: 机器人控制基本接口头文件，包含对车底盘及云台的基本接口。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-3-4
///修订历史：
///2018.6.13:哨兵协议versio2.1
////////////////////////////////////////////////////////////////////////////////
#include "serial_port.h"
#include "serial_packet.h"

#ifndef RMDEMO_SERIAL_INTERFACE_H
#define RMDEMO_SERIAL_INTERFACE_H

//协议

typedef enum:unsigned char {
    CMD_SERIAL_CHASSIS_POS_CONTROL = 0x02,
    CMD_SERIAL_CHASSIS_CONST_MOVE = 0x03,
    CMD_SERIAL_CHASSIS_RANDOM_MOVE = 0x04,
    CMD_SERIAL_CHASSIS_SWING_MOVE = 0x05,

    CMD_SERIAL_YUNTAI_RELATIVE_ANGLE = 0x10,
    CMD_SERIAL_YUNTAI_ABSOLUTE_ANGLE = 0x11,
    CMD_SERIAL_SHOOT = 0x12,
    CMD_SERIAL_YUNTAI_GLOBAL_SCAN = 0x13,
    CMD_SERIAL_YUNTAI_LOCAL_SCAN = 0x14,

    CMD_SERIAL_BLOOD_INFO_RECV = 0x90,
    CMD_SERIAL_CHASSIS_INFO_RECV = 0xb0,
} SerialPortCMD;


class SerialInterface
{
public:
    SerialInterface(void);
    ~SerialInterface(void);

private:
    SerialPort mMcuSerialPort;

public:

    struct Point2f{
        float pitch;
        float yaw;
        Point2f(){}
        Point2f(float p, float y):pitch(p), yaw(y){}
    };

    /** 初始化函数
    *  @param:  std::string devPath :串口设备路径
    *  @return: int :错误号，0代表无错误，１代表发生错误。
    */
    int init(std::string devPath);

    //查询串口是否打开
    bool isOpen();

    /** 命令数据发送函数
     *根据协议数据帧格式，封装串口发送函数。
     *  @param:  SerialPacket sendPacket :待发送的数据包
     *  @return: int :错误号，0代表无错误，１代表发生错误。
     *  @note:   数据包构成参考serial_packet.h/cpp
     */
    int dataSend(SerialPacket sendPacket);

    /** 命令数据接收函数
     *根据协议数据帧格式，封装串口接收函数，包括协议帧的检查机制。
     *  @return: int :错误号，0代表无错误，１代表发生错误。
     *  @note:   数据包构成参考serial_packet.h/cpp
     */
    int dataRecv(SerialPacket &recvPacket);

    /** 底盘停止设置
    *  @param:  void
    *  @return: void
    *  @note :
    */
    void chassisStopSet();

    /** 底盘位置设置
     * @param: pos_move, 底盘要移动到的位置,靠墙一端为0。单位cm.
     * @param: move_level, 底盘移动等级(如,10,14,20等,最大100)
     */
    void chassisPosSet(short int pos_move, int move_level);

    /** 底盘匀速全局运动
     * @param: move_level, 底盘移动等级(如,10,14,20等,最大100)
     */
    void chassisConstMove(int move_level);

    /** 底盘随机运动控制
     * @param: move_level, 底盘移动等级(如,10,14,20等,最大100)
     * @param: min_pos, 随机移动区域的最小位置
     * @param: max_pos, 随机移动区域的最大位置
     */
    void chassisRandomMove(int move_level, short int min_pos, short int max_pos);

    /** 底盘摇摆运动
     * @param: move_level, 底盘移动等级(如,10,14,20等,最大100)
     */
    void chassisSwingMove(int move_level);

    /** 云台相对控制
     * @param: pitch, 代表pitch角度,相对角度,单位为度,正数代表下,负数代表上。
     * @param: yaw, 代表yaw角度,相对角度,单位为度,逆时针为正
     * @param: speed, 代表速度标志位,0x00代表正常(快速响应),0x01代表低速
     */
    void yuntaiRelativeControl(float pitch, float yaw, unsigned char speed);

    /** 云台绝对控制
     * @param: pitch, 代表pitch角度,相对角度,单位为度,正数代表下,负数代表上。
     * @param: yaw, 代表yaw角度,相对角度,单位为度,逆时针为正
     * @param: speed, 代表速度标志位,0x00代表正常(快速响应),0x01代表低速
     */
    void yuntaiAbsoluteControl(float pitch, float yaw, unsigned char speed);

    /** 射击
     * @param: bullet_count, uchar,代表一次射击弹量
     */
    void shoot(unsigned char bullet_count);

    /** 云台全局扫描
     * @param: pitch_move_level, pitch移动等级(如,10,14,20等,最大100)
     * @param: yaw_move_level, yaw移动等级(如,10,14,20等,最大100)
     * @note: 在轨道上yaw匀速旋转,pitch上下摆动一定角度运行
     */
    void globalScanning(int pitch_move_level, int yaw_move_level);

    /** 云台局部扫描
     * @param: yaw, 代表yaw角度,及摇摆扫描的中心,绝对角度,单位为度,逆时针为正
     * @param: pitch_move_level, pitch移动等级(如,10,14,20等,最大100)
     * @param: yaw_move_level, yaw移动等级(如,10,14,20等,最大100)
     * @note: 在轨道上yaw左右摆动一定角度(以yaw为中心的的正负40度),pitch上下摆动一定角度运行
     */
    void localScanning(float yaw, int pitch_move_level, int yaw_move_level);
};



#endif
