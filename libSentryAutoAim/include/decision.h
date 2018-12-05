#include"behavior_tree.h"
#include"action_behavior.h"

class Decision:public bt::BehaviorTree{
    public:
        Decision(bt::Blackboard::Ptr& blackboard_ptr,int cycle_duration):
            BehaviorTree::BehaviorTree(blackboard_ptr, cycle_duration){}
        ~Decision(){}
    
        virtual void initBT();
    
};