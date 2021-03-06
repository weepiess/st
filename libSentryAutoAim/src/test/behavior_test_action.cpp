#include "behavior_test_action.h"

BehaviorTestAction::BehaviorTestAction(const Blackboard::Ptr &blackboard_ptr):
        ActionNode::ActionNode("behavior_node_test", blackboard_ptr){}

void BehaviorTestAction::onInitialize(){
    //chassis_pos = blackboard_ptr_->getCurrPos();
    LOG_WARNING<<chassis_pos;
}

bt::BehaviorState BehaviorTestAction::update(){
    //blackboard_ptr_->chassisPosControl(200, 10);

    //blackboard_ptr_->chassisRandomMove(30, 0, 400);

    //blackboard_ptr_->chassisSwingMove(10);

    //blackboard_ptr_->chassisConstSpeedMove(10);

    //blackboard_ptr_->yuntaiRelativeControl(-1, 1, 0);

    //blackboard_ptr_->globalScanning(10, 10);

    //blackboard_ptr_->localScanning(30, 10, 10);

    //blackboard_ptr_->shoot(1);
    
    return BehaviorState::SUCCESS;
}

void BehaviorTestAction::onTerminate(BehaviorState state){
    switch(state){
        case BehaviorState::SUCCESS:
            LOG_INFO<<"update success!!!";
            break;
        default:
            LOG_INFO<<"update failure!!!";
            break;
    }
}