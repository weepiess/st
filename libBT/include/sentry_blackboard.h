#ifndef SENTRY_BLACKBOARD_H
#define SENTRY_BLACKBOARD_H
typedef unsigned char uchar;

#include <memory>
#include "log.h"

//输入血量信息
struct InBloodInfo{
    int blood_remain; //剩余血量
    int blood_loss_once; //上次被打丢失的血量
    uchar wounded_armor_id; //被打装甲板的id，0x00表示0,0x01表示1
    uchar is_self_save; //是否进入自保模式，0x00没有进入，0x01进入

    InBloodInfo():
        blood_remain(600),
        blood_loss_once(0),
        wounded_armor_id(-1),
        is_self_save(0) {}
};

//输入底盘信息
struct InChassisInfo{
    float pitch; //相对于水平的pitch绝对角度，正数向下
    float yaw; //相对于直轨道的绝对角度，逆时针为正
    short int current_pos; //底盘当前位置，靠墙为0，单位cm
    uchar is_bullet_remain; //是否剩余子弹，0x00为有，0x01为没有
};

//输出底盘位置控制
struct OutChassisPos{
    bool is_update = false;
    short int pos_to_move;
    int move_level;
};

//输出底盘匀速全局运动控制
struct OutChassisConstMove{
    bool is_update = false;
    int move_level;
};

//输出底盘随机运动控制
struct OutChassisRandomMove{
    bool is_update = false;
    int move_level;
    short int min_pos;
    short int max_pos;
};

//输出底盘摇摆运动控制
struct OutChassisSwingMove{
    bool is_update = false;
    int move_level;
};

//输出云台相对运动控制
struct OutYuntaiRelativeAngle{
    bool is_update = false;
    float pitch;
    float yaw;
    uchar speed_signal;
};

//输出射击控制
struct OutShoot{
    bool is_update = false;
    uchar bullet_count;
};

//输出云台全局扫描控制
struct OutGlobalScan{
    bool is_update = false;
    int pitch_move_level;
    int yaw_move_level;
};

//输出云台局部扫描控制
struct OutLocalScan{
    bool is_update = false;
    float yaw;
    int pitch_move_level;
    int yaw_move_level;
};

class SentryBlackboard{

public:
    typedef std::shared_ptr<SentryBlackboard> Ptr;

    SentryBlackboard();
    ~SentryBlackboard();

public:
    //外部调用更新数据
    void updateBloodInfo(int remain, int loss, uchar armor_id, uchar is_save);
    void updateChassisInfo(float pitch, float yaw, short int curr_pos, uchar is_bullet_remain);

    //给行为树的节点调用
    void chassisConstSpeedMove(int move_level);
    void chassisPosControl(short int chassis_pos, int move_level);
    void chassisRandomMove(int move_level, short int min_pos, short int max_pos);
    void chassisSwingMove(int move_level);

    void yuntaiRelativeControl(float pitch, float yaw, uchar speed);
    void shoot(uchar bullet_count);
    void globalScanning(int pitch_move_level, int yaw_move_level);
    void localScanning(float yaw, int pitch_move_level, int yaw_move_level);

    //行为树调用获取当前的状态
    int getBloodRemain();
    int getBloodLoss();
    uchar getArmorId();
    uchar isSelfSave();
    
    float getCurrPicth();
    float getCurrYaw();
    short int getCurrPos();
    uchar isBulletRemain();

    //给外部发送的消息
    OutChassisPos* getOutChassisPos();
    OutChassisConstMove* getOutChassisConstMove();
    OutChassisRandomMove* getOutChassisRandomMove();
    OutChassisSwingMove* getOutChassisSwingMove();

    OutShoot* getOutShoot();
    OutYuntaiRelativeAngle* getOutRelativeAngle();
    OutGlobalScan* getOutGlobalScan();
    OutLocalScan* getOutLocalScan();

private:
    InBloodInfo in_blood_info;
    InChassisInfo in_chassis_info;

    OutChassisPos out_chassis_pos;
    OutChassisConstMove out_chassis_const_move;
    OutChassisRandomMove out_chassis_random_move;
    OutChassisSwingMove out_chassis_swing_move;

    OutShoot out_shoot;
    OutGlobalScan out_global_scan;
    OutLocalScan out_local_scan;
    OutYuntaiRelativeAngle out_yuntai_relative_angle;
}; //class

#endif //SENTRY_BLACKBOARD_H