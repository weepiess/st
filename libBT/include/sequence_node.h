#ifndef LIBBT_SEQUENCE_NODE_H
#define LIBBT_SEQUENCE_NODE_H

#include <composite_node.h>

namespace bt{

class SequenceNode: public CompositeNode{
public:
    SequenceNode(std::string name, const Blackboard::Ptr &blackboard_ptr):
        CompositeNode::CompositeNode(name, BehaviorType::SEQUENCE, blackboard_ptr) {}

    virtual ~SequenceNode() = default;

protected:
    virtual BehaviorState Update();
    virtual void OnInitialize();
    virtual void OnTerminate(BehaviorState state);

}; //class
}; //namespace bt

#endif //LIB_SEQUENCE_NODE_H