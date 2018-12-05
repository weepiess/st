#include"behavior_tree.h"
#include"blackboard.h"
#include"action_node.h"
namespace bt{

//慢速全轨道巡逻动作
class SlowPatrolAction: public ActionNode {
    public:
        SlowPatrolAction(const Blackboard::Ptr &blackboard_ptr) :
            ActionNode::ActionNode("slow_patrol_action",blackboard_ptr){

            }
         ~SlowPatrolAction() {}
    private:
         void onInitialize();
         BehaviorState update();
         void onTerminate(BehaviorState state);
};

//高速全轨道巡逻动作
class FastPatrolAction: public ActionNode {
    public:
        FastPatrolAction(const Blackboard::Ptr &blackboard_ptr) :
            ActionNode::ActionNode("fast_patrol_action", blackboard_ptr){

            }
        ~FastPatrolAction(){}
    private:
        void onInitialize();
         BehaviorState update();
         void onTerminate(BehaviorState state);
};



//单发射击动作
class ShootingSingleAction : public ActionNode{
    public:
        ShootingSingleAction(const Blackboard::Ptr &blackboard_ptr) :
            ActionNode::ActionNode("shooting_single_action",blackboard_ptr){

            }
        ~ShootingSingleAction(){}
    private:
         void onInitialize();
         BehaviorState update();
         void onTerminate(BehaviorState state);
};

//五连发射击动作
class ShootingFiveAction : public ActionNode{
    public:
        ShootingFiveAction(const Blackboard::Ptr &blackboard_ptr) :
            ActionNode::ActionNode("shooting_five_action",blackboard_ptr){

            }
         ~ShootingFiveAction() {}
    private:
         void onInitialize();
         BehaviorState update();
         void onTerminate(BehaviorState state);
};



};//bt



