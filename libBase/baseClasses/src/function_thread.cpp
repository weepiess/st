#include "function_thread.h"

FunctionThread::FunctionThread(std::function<void()> function_){
    function = std::move(function_);
}

FunctionThread::~FunctionThread(){}

void FunctionThread::run(){
    function();
}