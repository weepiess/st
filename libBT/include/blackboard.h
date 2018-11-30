#ifndef LIBBT_BLACKBOARD_H
#define LIBBT_BLACKBOARD_H

#include "log.h"
#include <memory>

namespace bt{

class Blackboard{
public:
    typedef std::shared_ptr<bt::Blackboard> Ptr;

    Blackboard(){}
    ~Blackboard(){}
};
}; //namespace bt

#endif //LIBBT_BLACKBOARD_H