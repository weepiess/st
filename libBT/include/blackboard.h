#ifndef BT_BLACKBOARD
#define BT_BLACKBOARD

#include "serial_interface.h"
#include "mind_vision.h"
#include "usb_capture_with_thread.h"
#include <memory>
#include "base_aim.h"
#include <mutex>

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

//输入检测到的装甲板信息
struct InArmorDetectInfo{
    bool is_found = false;
    vector<Armor> detected_armor;
    int follow_armor_index = -1; //选择跟踪的装甲板下标，-1表示不跟踪

    InArmorDetectInfo(){
        //初始化为装甲板预留5个雅座
        detected_armor.reserve(5);
    }
};
    
class Blackboard{
public:
    Blackboard();
    ~Blackboard();

    typedef std::shared_ptr<Blackboard> Ptr;

public:
    //初始化函数
    void init(bool is_enemy_red_, string serial_path);

    //硬件资源
    SerialInterface* getSerialInterface();
    MindVision* getVisionCapture();

    //32发送，主机接收的状态信息
    void updateBloodInfo(int remain, int loss, uchar armor_id, uchar is_save);
    void updateChassisInfo(float pitch, float yaw, short int curr_pos, uchar is_bullet_remain);

    //行为树获取状态
    int getBloodRemain();
    int getBloodLoss();
    uchar getArmorId();
    uchar isSelfSave();
    
    float getCurrPicth();
    float getCurrYaw();
    short int getCurrPos();
    uchar isBulletRemain();

    InArmorDetectInfo* getArmorDetectInfo();
    bool isEnemyRed();

    //行为树调用更新状态
    void updateArmorInfo(bool is_found, const vector<Armor>& detected_armor_);

private:
    //硬件资源
    SerialInterface serial_interface;
    MindVision vision_capture;

    //状态信息
    InArmorDetectInfo armor_detect_info;
    InBloodInfo blood_info;
    InChassisInfo chassis_info;

    bool is_enemy_red;

    //互斥量
    std::mutex blood_mutex;
    std::mutex chassis_mutex;
}; //class

#endif //BT_BLACKBOARD