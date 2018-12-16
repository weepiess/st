#include "blackboard.h"

Blackboard::Blackboard(){}

Blackboard::~Blackboard(){}

void Blackboard::init(bool is_enemy_red_, string serial_path){
    is_enemy_red = is_enemy_red_;
    vision_capture.init(is_enemy_red_); //工业相机初始化
    if(serial_path != "") //串口初始化
        serial_interface.init(serial_path);
}

/*---------------------外部更新行为树需要用到的数据---------------------*/
void Blackboard::updateBloodInfo(int remain, int loss, uchar armor_id, uchar is_save){
    std::lock_guard<std::mutex> blood_lock(blood_mutex); //加锁
    blood_info.blood_remain = remain;
    blood_info.blood_loss_once = loss;
    blood_info.wounded_armor_id = armor_id;
    blood_info.is_self_save = is_save;
}

void Blackboard::updateChassisInfo(float pitch, float yaw, short int curr_pos, uchar is_bullet_remain){
    std::lock_guard<std::mutex> chassis_lock(chassis_mutex); //加锁
    chassis_info.pitch = pitch;
    chassis_info.yaw = yaw;
    chassis_info.current_pos = curr_pos;
    chassis_info.is_bullet_remain = is_bullet_remain;
}

void Blackboard::updateArmorInfo(bool is_found, const vector<Armor>& detected_armor_){
    armor_detect_info.is_found = is_found;
    armor_detect_info.detected_armor = detected_armor_;
}

/*---------------------行为树获取数据---------------------*/
int Blackboard::getBloodRemain(){
    return blood_info.blood_remain;
}

int Blackboard::getBloodLoss(){
    return blood_info.blood_loss_once;
}

uchar Blackboard::getArmorId(){
    return blood_info.wounded_armor_id;
}

uchar Blackboard::isSelfSave(){
    return blood_info.is_self_save;
}

float Blackboard::getCurrPicth(){
    return chassis_info.pitch;
}

float Blackboard::getCurrYaw(){
    return chassis_info.yaw;
}

short int Blackboard::getCurrPos(){
    return chassis_info.current_pos;
}

uchar Blackboard::isBulletRemain(){
    return chassis_info.is_bullet_remain;
}

InArmorDetectInfo* Blackboard::getArmorDetectInfo(){
    return &armor_detect_info;
}

bool Blackboard::isEnemyRed(){
    return is_enemy_red;
}

/*------------------------硬件资源---------------------*/
SerialInterface* Blackboard::getSerialInterface(){
    return &serial_interface;
}

MindVision* Blackboard::getVisionCapture(){
    return &vision_capture;
}