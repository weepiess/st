#ifndef SENTRY_BEHAVIOR_TREE
#define SENTRY_BEHAVIOR_TREE

#include "behavior_tree.h"

#include "actions/avoid_enemy_action.h"
#include "actions/distinguish_armor_action.h"
#include "actions/enemy_detect_action.h"
#include "actions/escape_action.h"
#include "actions/fast_patrol_action.h"
#include "actions/shooting_single_action.h"

class SentryBehaviorTree: public bt::BehaviorTree{
public:
    SentryBehaviorTree(const Blackboard::Ptr& blackboard_ptr, int cycle_duration):
        BehaviorTree::BehaviorTree(blackboard_ptr, cycle_duration){}

    virtual ~SentryBehaviorTree() noexcept = default;

protected:
    virtual void initBT() override;
};

#endif