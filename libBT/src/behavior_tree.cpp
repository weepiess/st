#include <behavior_tree.h>

void bt::BehaviorTree::execute(){
    //必须在之前调用
    initBT();
    running_ = true;
    mTreeThread = new std::thread(&BehaviorTree::executeInThread, this);
}

void bt::BehaviorTree::stop(){
    running_ = false;
    mTreeThread->join();
    LOG_WARNING<<"thread has been destoried!";
}

void bt::BehaviorTree::executeInThread(){
    while (running_) {
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        root_node_ptr->run();

        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        std::chrono::milliseconds execution_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::chrono::milliseconds sleep_time = cycle_duration_ - execution_duration;
        
        if (sleep_time > std::chrono::microseconds(0)) {
            std::this_thread::sleep_for(sleep_time);
            LOG_INFO << "sleep: " << sleep_time.count() << "ms";
        } else {
            LOG_WARNING << "The time tick once is " << execution_duration.count() << " beyond the expected time "
                        << cycle_duration_.count();
        }
        LOG_INFO << "----------------------------------";
        
    }
}