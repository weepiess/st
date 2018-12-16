#include "behavior_test_tree.h"

BehaviorTestTree::BehaviorTestTree(const Blackboard::Ptr& blackboard_ptr, int cycle_duration):
        BehaviorTree::BehaviorTree(blackboard_ptr, cycle_duration){}

void BehaviorTestTree::initBT(){
    auto test_node = std::make_shared<BehaviorTestAction>(blackboard_ptr);

    auto root_node = std::make_shared<SequenceNode>("root_node", blackboard_ptr);
    root_node->addChildren(test_node);

    root_node_ptr = root_node;
}