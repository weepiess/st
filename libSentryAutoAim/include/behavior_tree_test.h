#ifndef SENTRY_BEHAVIOR_TREE_H
#define SENTRY_BEHAVIOR_TREE_H

#include "behavior_tree.h"

class BehaviorTreeTest: public bt::BehaviorTree{
public:
    BehaviorTreeTest(bt::Blackboard::Ptr& blackboard_);
    ~BehaviorTreeTest();

public:
    
};

#endif //SENTRY_BEHAVIOR_TREE_H