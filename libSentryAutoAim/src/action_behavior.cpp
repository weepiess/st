#include"action_behavior.h"
using namespace bt;
using namespace std;

void SlowPatrolAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}
BehaviorState SlowPatrolAction::update(){
    blackboard_ptr_->chassisSwingMove(50);
    return BehaviorState::SUCCESS;
}
void SlowPatrolAction::onTerminate(BehaviorState state){
    switch (state){
      case BehaviorState::IDLE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" IDLE!";
        break;
      case BehaviorState::SUCCESS:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" SUCCESS!";
        break;
      case BehaviorState::FAILURE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" FAILURE!";
        break;
      default:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" ERROR!";
        return;
    }
}


void FastPatrolAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}
BehaviorState FastPatrolAction::update(){
    blackboard_ptr_->chassisSwingMove(100);
    blackboard_ptr_->globalScanning(50,50);
    return BehaviorState::SUCCESS;
}
void FastPatrolAction::onTerminate(BehaviorState state){
    switch (state){
      case BehaviorState::IDLE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" IDLE!";
        break;
      case BehaviorState::SUCCESS:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" SUCCESS!";
        break;
      case BehaviorState::FAILURE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" FAILURE!";
        break;
      default:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" ERROR!";
        return;
    }
}


void ShootingSingleAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}
BehaviorState ShootingSingleAction::update(){
    cv::Point2f angle;
    bool if_shoot;
    if(blackboard_ptr_->autoAim.aim(blackboard_ptr_->getCurrPitch(),blackboard_ptr_->getCurrYaw(),angle,1,if_shoot,35) == BaseAim::AIM_TARGET_FOUND){
        blackboard_ptr_->yuntaiRelativeControl(angle.x,angle.y,0x00);
        if(if_shoot){
            blackboard_ptr_->shoot(0x01);
        }
    }
    return BehaviorState::SUCCESS;
}
void ShootingSingleAction::onTerminate(BehaviorState state){
    switch (state){
      case BehaviorState::IDLE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" IDLE!";
        break;
      case BehaviorState::SUCCESS:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" SUCCESS!";
        break;
      case BehaviorState::FAILURE:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" FAILURE!";
        break;
      default:
        LOG_INFO<<name_<<" "<<__FUNCTION__<<" ERROR!";
        return;
    }
}





