//用于在特定时候开启线程，运行类中的某个函数
#ifndef FUNTION_THREAD
#define FUNTION_THREAD

#include <thread>
#include "base_thread.h"

class FunctionThread: public BaseThread{
public:
    FunctionThread(std::function<void()> function_);
    ~FunctionThread();

private:
    virtual void run() override;

    //需要运行的函数
    std::function<void()> function;
};

#endif