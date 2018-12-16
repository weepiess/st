#ifndef SENTRY_FAST_PATROL_ACTION
#define SENTRY_FAST_PATROL_ACTION

#include "action_node.h"

using namespace bt;

//高速全轨道巡逻动作
class FastPatrolAction: public ActionNode {
public:
    FastPatrolAction(const Blackboard::Ptr & blackboard_ptr_);
    virtual ~FastPatrolAction() = default;

protected:
    virtual void onInitialize();
    virtual BehaviorState update();
    virtual void onTerminate(BehaviorState state);
};

#endif