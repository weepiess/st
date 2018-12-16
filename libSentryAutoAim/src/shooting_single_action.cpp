#include "shooting_single_action.h"

ShootingSingleAction::ShootingSingleAction(const Blackboard::Ptr & blackboard_ptr):
    ActionNode::ActionNode("shooting_single_action", blackboard_ptr){}

void ShootingSingleAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}

bt::BehaviorState ShootingSingleAction::update(){
    blackboard_ptr_->chassisSwingMove(40);
    blackboard_ptr_->shoot(1);
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