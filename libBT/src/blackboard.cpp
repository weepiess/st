#include"blackboard.h"
using namespace bt;
/*---------------------外部更新行为树需要用到的数据---------------------*/
void Blackboard::updateBloodInfo(int remain, int loss, uchar armor_id, uchar is_save){
    in_blood_info.blood_remain = remain;
    in_blood_info.blood_loss_once = loss;
    in_blood_info.wounded_armor_id = armor_id;
    in_blood_info.is_self_save = is_save;
}

void Blackboard::updateChassisInfo(float pitch, float yaw, short int curr_pos, uchar is_bullet_remain){
    in_chassis_info.pitch = pitch;
    in_chassis_info.yaw = yaw;
    in_chassis_info.current_pos = curr_pos;
    in_chassis_info.is_bullet_remain = is_bullet_remain;
}

void Blackboard::updateImg(cv::Mat img){
    src = img;
}

/*---------------------行为树向外传送的底盘控制---------------------*/
void Blackboard::chassisConstSpeedMove(int move_level){
    out_chassis_const_move.move_level = move_level;
    out_chassis_const_move.is_update = true;
}

void Blackboard::chassisPosControl(short int chassis_pos, int move_level){
    out_chassis_pos.pos_to_move = chassis_pos;
    out_chassis_pos.move_level = move_level;
    out_chassis_pos.is_update = true;
}

void Blackboard::chassisRandomMove(int move_level, short int min_pos, short int max_pos){
    out_chassis_random_move.move_level = move_level;
    out_chassis_random_move.min_pos = min_pos;
    out_chassis_random_move.max_pos = max_pos;
    out_chassis_random_move.is_update = true;
}

void Blackboard::chassisSwingMove(int move_level){
    out_chassis_swing_move.move_level = move_level;
    out_chassis_swing_move.is_update = true;
}

/*---------------------行为树向外传送的云台控制---------------------*/
void Blackboard::yuntaiRelativeControl(float pitch, float yaw, uchar speed){
    out_yuntai_relative_angle.pitch = pitch;
    out_yuntai_relative_angle.yaw = yaw;
    out_yuntai_relative_angle.speed_signal = speed;
    out_yuntai_relative_angle.is_update = true;
}

void Blackboard::shoot(uchar bullet_count){
    out_shoot.bullet_count = bullet_count;
    out_shoot.bullet_count = true;
}

void Blackboard::globalScanning(int pitch_move_level, int yaw_move_level){
    out_global_scan.pitch_move_level = pitch_move_level;
    out_global_scan.yaw_move_level = yaw_move_level;
    out_global_scan.is_update = true;
}

void Blackboard::localScanning(float yaw, int pitch_move_level, int yaw_move_level){
    out_local_scan.yaw = yaw;
    out_local_scan.pitch_move_level = pitch_move_level;
    out_local_scan.yaw_move_level = yaw_move_level;
    out_local_scan.is_update = true;
}


/*---------------------行为树获取数据---------------------*/
int Blackboard::getBloodRemain(){
    return in_blood_info.blood_remain;
}

int Blackboard::getBloodLoss(){
    return in_blood_info.blood_loss_once;
}

uchar Blackboard::getArmorId(){
    return in_blood_info.wounded_armor_id;
}

uchar Blackboard::isSelfSave(){
    return in_blood_info.is_self_save;
}

float Blackboard::getCurrPitch(){
    return in_chassis_info.pitch;
}

float Blackboard::getCurrYaw(){
    return in_chassis_info.yaw;
}

short int Blackboard::getCurrPos(){
    return in_chassis_info.current_pos;
}

uchar Blackboard::isBulletRemain(){
    return in_chassis_info.is_bullet_remain;
}



cv::Mat Blackboard::getImg(){
    return src;
}

/*---------------------外部获取数据---------------------*/
OutChassisPos* Blackboard::getOutChassisPos(){
    if(out_chassis_pos.is_update){
        out_chassis_pos.is_update = false;
        return &out_chassis_pos;
    } else return NULL;
}

OutChassisConstMove* Blackboard::getOutChassisConstMove(){
    if(out_chassis_const_move.is_update){
        out_chassis_const_move.is_update = false;
        return &out_chassis_const_move;
    } else return NULL;
}

OutChassisRandomMove* Blackboard::getOutChassisRandomMove(){
    if(out_chassis_random_move.is_update){
        out_chassis_random_move.is_update = false;
        return &out_chassis_random_move;
    } else return NULL;
}

OutChassisSwingMove* Blackboard::getOutChassisSwingMove(){
    if(out_chassis_swing_move.is_update){
        out_chassis_swing_move.is_update = false;
        return &out_chassis_swing_move;
    } else return NULL;
}

OutShoot* Blackboard::getOutShoot(){
    if(out_shoot.is_update){
        out_shoot.is_update = false;
        return &out_shoot;
    } else return NULL;
}

OutYuntaiRelativeAngle* Blackboard::getOutRelativeAngle(){
    if(out_yuntai_relative_angle.is_update){
        out_yuntai_relative_angle.is_update = false;
        return &out_yuntai_relative_angle;
    } else return NULL;   
}

OutGlobalScan* Blackboard::getOutGlobalScan(){
    if(out_global_scan.is_update){
        out_global_scan.is_update = false;
        return &out_global_scan;
    } else return NULL;
}

OutLocalScan* Blackboard::getOutLocalScan(){
    if(out_local_scan.is_update){
        out_local_scan.is_update = false;
        return &out_local_scan;
    } else return NULL;
}