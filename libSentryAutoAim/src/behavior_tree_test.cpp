#include <behavior_tree_test.h>

void BehaviorTreeTest::initBT(){
    auto test_node = std::make_shared<BehaviorNodeTest>(blackboard_ptr);

    auto root_node = std::make_shared<SequenceNode>("root_node", blackboard_ptr);
    root_node->addChildren(test_node);

    root_node_ptr = root_node;
}