#ifndef LIBBT_BEHAVIOR_TREE_H
#define LIBBT_BEHAVIOR_TREE_H

#include "action_node.h"

#include "composite_node.h"
#include "decorator_node.h"
#include "precondition_node.h"

#include "parallel_node.h"
#include "selector_node.h"
#include "sequence_node.h"

namespace bt{

class BehaviorTree{
public:
    typedef std::shared_ptr<BehaviorTree> Ptr;

    BehaviorTree(const Blackboard::Ptr& blackboard_ptr, int cycle_duration):
        blackboard_ptr(blackboard_ptr),
        cycle_duration_(cycle_duration),
        running_(false) {}

    virtual ~BehaviorTree() = default;

    void execute();

    void stop();

protected:
    //子类需要实现该函数，在该函数中创建节点并连接成树，最后必须将根节点的指针传给root_node_!!!
    virtual void initBT() = 0;

    BehaviorNode::Ptr root_node_ptr;
    Blackboard::Ptr blackboard_ptr; //该指针需要传给每个创建的节点
    std::chrono::milliseconds cycle_duration_;
    bool running_;

}; //class
}; //namespace bt

#endif //LIBBT_BEHAVIOR_TREE_H