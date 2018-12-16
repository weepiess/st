#ifndef SENTRY_ESCAPE_ACTION
#define SENTRY_ESCAPE_ACTION

#include "action_node.h"
#include "blackboard.h"

using namespace bt;

class EscapeAction: public ActionNode{
public:
    EscapeAction(const Blackboard::Ptr & blackboard_ptr_);
    virtual ~EscapeAction() = default;

protected:
    virtual void onInitialize();
    virtual BehaviorState update();
    virtual void onTerminate(BehaviorState state);
};

#endif