#ifndef SENTRY_AVOID_ENEMY_ACTION
#define SENTRY_AVOID_ENEMY_ACTION

#include "action_node.h"
#include "blackboard.h"

//遇到敌人后跑到特殊位置
class AvoidEnemyAction: public ActionNode{
public:
    AvoidEnemyAction(const Blackboard::Ptr & blackboard_ptr_);
    virtual ~AvoidEnemyAction() = default;
};

#endif //SENTRY_AVOID_ENEMY_ACTION