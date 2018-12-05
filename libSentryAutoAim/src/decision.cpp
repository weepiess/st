#include"decision.h"
using namespace bt;
void Decision::initBT(){
    auto shoot_single_action_ = std::make_shared<ShootingSingleAction>(blackboard_ptr);
    auto fast_patrol_action_ = std::make_shared<FastPatrolAction>(blackboard_ptr);
    auto enermy_detected_condition = std::make_shared<PreconditionNode>("enermy detected condition" ,
                                                                         blackboard_ptr, shoot_single_action_,
                                                                         [&](){
                                                                             if (blackboard_ptr->autoAim.ifGetArmor(blackboard_ptr->getImg())){
                                                                                 return true;
                                                                             }else return false;
                                                                         },AbortType::BOTH);
    auto hp_selector = std::make_shared<SelectorNode>("hp selector",blackboard_ptr);
    hp_selector->addChildren(enermy_detected_condition);
    hp_selector->addChildren(fast_patrol_action_);
    root_node_ptr=hp_selector;
}