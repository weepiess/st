#ifndef SENTRY_BEHAVIOR_TEST_TREE
#define SENTRY_BEHAVIOR_TEST_TREE

#include "behavior_tree.h"
#include "behavior_test_action.h"

using namespace bt;

class BehaviorTestTree: public bt::BehaviorTree{
public:
    BehaviorTestTree(const Blackboard::Ptr& blackboard_ptr_, int cycle_duration);

    virtual ~BehaviorTestTree() = default;

public:
    virtual void initBT();
};

#endif //SENTRY_BEHAVIOR_TREE_H