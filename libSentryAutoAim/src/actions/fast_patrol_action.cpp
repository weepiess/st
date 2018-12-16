#include "fast_patrol_action.h"

FastPatrolAction::FastPatrolAction(const Blackboard::Ptr & blackboard_ptr):
      ActionNode::ActionNode("fast_patrol_action", blackboard_ptr){}

void FastPatrolAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}

bt::BehaviorState FastPatrolAction::update(){
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