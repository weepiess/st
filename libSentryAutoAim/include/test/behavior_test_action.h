#ifndef SENTRY_BEHAVIOR_TEST_ACTION
#define SENTRY_BEHAVIOR_TEST_ACTION

#include "action_node.h"
#include <opencv2/opencv.hpp>

using namespace bt;

//测试节点
class BehaviorTestAction: public ActionNode{
public:
    BehaviorTestAction(const Blackboard::Ptr & blackboard_ptr_);

    virtual ~BehaviorTestAction() = default;

public:
    virtual void onInitialize();
    virtual BehaviorState update();
    virtual void onTerminate(BehaviorState state);

private:
    short chassis_pos = 0;
};

#endif //SENTRY_BEHAVIOR_TEST_ACTION