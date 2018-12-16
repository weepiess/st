#ifndef SENTRY_SHOOTING_SINGLE_ACTION
#define SENTRY_SHOOTING_SINGLE_ACTION

#include "action_node.h"

using namespace bt;

//单发射击动作
class ShootingSingleAction: public ActionNode{
public:
    ShootingSingleAction(const Blackboard::Ptr & blackboard_ptr_);
    virtual ~ShootingSingleAction() noexcept = default;
    
protected:
    virtual void onInitialize();
    virtual BehaviorState update();
    virtual void onTerminate(BehaviorState state);

private:
    PNPSolver pnp_solver;
};

#endif