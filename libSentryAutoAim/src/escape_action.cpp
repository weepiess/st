#include "escape_action.h"

EscapeAction::EscapeAction(const Blackboard::Ptr & blackboard_ptr):
      ActionNode::ActionNode("fast_patrol_action", blackboard_ptr){}

void EscapeAction::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}

bt::BehaviorState EscapeAction::update(){
    
}

void EscapeAction::onTerminate(BehaviorState state){
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