#ifndef SENTRY_BEHAVIOR_TREE_H
#define SENTRY_BEHAVIOR_TREE_H

#include "behavior_tree.h"
#include "behavior_node_test.h"

using namespace bt;

class BehaviorTreeTest: public bt::BehaviorTree{
public:
    typedef std::shared_ptr<BehaviorNodeTest> Ptr;

    BehaviorTreeTest(SentryBlackboard::Ptr& blackboard_ptr, int cycle_duration):
        BehaviorTree::BehaviorTree(blackboard_ptr, cycle_duration){}

    ~BehaviorTreeTest(){}

public:
    virtual void initBT();
};

#endif //SENTRY_BEHAVIOR_TREE_H