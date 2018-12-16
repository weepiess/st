#include "sentry_behavior_tree.h"

//构造行为树
void SentryBehaviorTree::initBT(){
    auto armor_detect_action = std::make_shared<EnemyDetectAction>(blackboard_ptr);
    auto shoot_single_action = std::make_shared<ShootingSingleAction>(blackboard_ptr);
    auto armor_detect_sequence = std::make_shared<SequenceNode>("armor_detect_sequence", blackboard_ptr);
    armor_detect_sequence->addChildren(armor_detect_action);
    armor_detect_sequence->addChildren(shoot_single_action);

    auto fast_patrol_action = std::make_shared<FastPatrolAction>(blackboard_ptr);
    /*
    auto enermy_detected_condition = std::make_shared<PreconditionNode>("enermy detected condition" ,
                                                                         blackboard_ptr, shoot_single_action,
                                                                         [&](){
                                                                             if (!blackboard_ptr->getArmorDetectInfo()->is_found){
                                                                                 return true;
                                                                             }else return false;
                                                                         },AbortType::BOTH);
    */
    auto root_selector = std::make_shared<SelectorNode>("root_selector", blackboard_ptr);
    root_selector->addChildren(armor_detect_sequence);
    root_selector->addChildren(fast_patrol_action);

    root_node_ptr = root_selector;
}