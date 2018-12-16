#ifndef SENTRY_DISTINGUISH_ARMOR_ACTION
#define SENTRY_DISTINGUISH_ARMOR_ACTION

#include "action_node.h"
#include <opencv2/opencv.hpp>

using namespace bt;

struct BigArmorParams{

};

//区分大小装甲板动作
class DistinguishArmorAction: public ActionNode{
public:
    DistinguishArmorAction(const Blackboard::Ptr & blackboard_ptr_);
    virtual ~DistinguishArmorAction() noexcept = default;

protected:
    //区分装甲板
    void distinguish();

private:
    //区分大装甲板的参数
    BigArmorParams params;
};

#endif