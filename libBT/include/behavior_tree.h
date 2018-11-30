#ifndef LIBBT_BEHAVIOR_TREE_H
#define LIBBT_BEHAVIOR_TREE_H

#include <action_node.h>

#include <composite_node.h>
#include <decorator_node.h>
#include <precondition_node.h>

#include <parallel_node.h>
#include <selector_node.h>
#include <sequence_node.h>

namespace bt{

class BehaviorTree{
public:
    BehaviorTree(BehaviorNode::Ptr root_node, int cycle_duration) :
        root_node_(root_node),
        cycle_duration_(cycle_duration),
        running_(false) {}

    void execute();

    void stop();

private:
    BehaviorNode::Ptr root_node_;
    std::chrono::milliseconds cycle_duration_;
    bool running_;
}; //class
}; //namespace bt

#endif //LIBBT_BEHAVIOR_TREE_H