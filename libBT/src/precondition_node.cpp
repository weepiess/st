#include <precondition_node.h>

bt::AbortType bt::PreconditionNode::getAbortType(){
    return abort_type_;
}

void bt::PreconditionNode::onInitialize(){
    LOG_INFO<<name_<<" "<<__FUNCTION__;
}

bool bt::PreconditionNode::precondition(){
    if(precondition_function_){
        return precondition_function_();
    } else{
        LOG_ERROR<<"There is no chosen precondition function, then return false by default!";
        return false;
    }
}

bt::BehaviorState bt::PreconditionNode::update(){
    if(child_node_ptr_ == nullptr){
        return BehaviorState::SUCCESS;
    }
    // Reevaluation
    if(reevaluation()){
        BehaviorState state = child_node_ptr_->run();
        return state;
    }
    return BehaviorState::FAILURE;
}

void bt::PreconditionNode::onTerminate(BehaviorState state){
    switch (state){
        case BehaviorState::IDLE:
            LOG_INFO<<name_<<" "<<__FUNCTION__<<" IDLE!";
            //TODO: the following recovery measure is called by parent node, and deliver to reset its running child node
            child_node_ptr_->reset();
            break;
        case BehaviorState::SUCCESS:
            LOG_INFO<<name_<<" "<<__FUNCTION__<<" SUCCESS!";
            break;
        case BehaviorState::FAILURE:
            LOG_INFO<<name_<<" "<<__FUNCTION__<<" FAILURE!";
            //TODO: the following recovery measure is in failure situation caused by precondition false.
            child_node_ptr_->reset();
            break;
        default:
            LOG_ERROR<<name_<<" "<<__FUNCTION__<<" ERROR!";
            return;
    }
}

bool bt::PreconditionNode::reevaluation(){

    // Back Reevaluation
    if (parent_node_ptr_ != nullptr && parent_node_ptr_->getBehaviorType() == BehaviorType::SELECTOR
        && (abort_type_ == AbortType::LOW_PRIORITY || abort_type_ ==  AbortType::BOTH)){
        auto parent_selector_node_ptr = std::dynamic_pointer_cast<SelectorNode>(parent_node_ptr_);

        auto parent_children = parent_selector_node_ptr->getChildren();
        auto iter_in_parent = std::find(parent_children.begin(), parent_children.end(), shared_from_this());
        if (iter_in_parent == parent_children.end()) {
            LOG_ERROR<< "Can't find current node in parent!";
            return false;
        }
        unsigned int index_in_parent = iter_in_parent - parent_children.begin();
        if (index_in_parent < parent_selector_node_ptr->getChildrenIndex()){
            if(precondition()){
                //Abort Measures
                LOG_INFO<<"Abort happens!"<<std::endl;
                parent_children.at(parent_selector_node_ptr->getChildrenIndex())->reset();
                parent_selector_node_ptr->setChildrenIndex(index_in_parent);
                return true;
        }
      else{
        return false;
      }
    }
  }
  // Self Reevaluation

  if(abort_type_== AbortType::SELF || abort_type_== AbortType::BOTH
      || child_node_ptr_->getBehaviorState() != BehaviorState::RUNNING){
    if(!precondition()){
      return false;
    }
  }
  return true;
}