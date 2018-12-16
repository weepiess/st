#ifndef SERIAL_LISTEN_THREAD
#define SERIAL_LISTEN_THREAD

#include "base_thread.h"
#include "blackboard.h"
#include "serial_packet.h"

class SerialListenThread: public BaseThread{
public:
    SerialListenThread();
    ~SerialListenThread();

public:
    void init(Blackboard::Ptr blackboard_ptr_);
    virtual void run() override;

private:
    Blackboard::Ptr blackboard_ptr;
};

#endif