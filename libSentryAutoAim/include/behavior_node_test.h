#ifndef SENTRY_BEHAVIOR_NODE_TEST
#define SENTRY_BEHAVIOR_NODE_TEST

#include "action_node.h"
#include "sentry_blackboard.h"
using namespace bt;

class BehaviorNodeTest: public ActionNode{
public:
    BehaviorNodeTest(const SentryBlackboard::Ptr &blackboard_ptr):
        ActionNode::ActionNode("BehaviorNodeTest", blackboard_ptr){}

    ~BehaviorNodeTest(){}

public:
    virtual void onInitialize();
    virtual BehaviorState update();
    virtual void onTerminate(BehaviorState state);

private:
    short chassis_pos = 0;
};

#endif //SENTRY_BEHAVIOR_NODE_TEST