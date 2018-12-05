#ifndef SENTRY_BEHAVIOR_TREE_H
#define SENTRY_BEHAVIOR_TREE_H

#include "behavior_tree.h"

class BehaviorTreeTest: public bt::BehaviorTree{
public:
   
    BehaviorTreeTest(bt::Blackboard::Ptr& blackboard_ptr, int cycle_duration):
        BehaviorTree::BehaviorTree(blackboard_ptr, cycle_duration){}
    ~BehaviorTreeTest();

public:
    
};

#endif //SENTRY_BEHAVIOR_TREE_H