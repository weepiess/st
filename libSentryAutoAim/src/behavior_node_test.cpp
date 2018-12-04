#include <behavior_tree_test.h>

void BehaviorNodeTest::onInitialize(){
    chassis_pos = blackboard_ptr_->getCurrPos();
    LOG_WARNING<<chassis_pos;
}

bt::BehaviorState BehaviorNodeTest::update(){
    chassis_pos += 2;
    blackboard_ptr_->chassisPosControl(chassis_pos, 10);
    return BehaviorState::SUCCESS;
}

void BehaviorNodeTest::onTerminate(BehaviorState state){
    switch(state){
        case BehaviorState::SUCCESS:
            LOG_INFO<<"update success!!!";
            break;
        default:
            LOG_INFO<<"update failure!!!";
            break;
    }
}