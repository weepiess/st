////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      MainFun Code for robot
///ALL RIGHTS RESERVED
///@file:main.cpp
///@brief: 无。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-9-4
///修订历史：
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "serial_listen_thread.h"
#include "serial_port_debug.h"
#include "log.h"

#include "sentry_behavior_tree.h"
#include "test/behavior_test_tree.h"
#include "blackboard.h"

using namespace std;

int main(int argc, char *argv[]){
    //初始化glog
    GLogWrapper glog_wrapper(argv[0]);
    LOG_INFO<<"glog init successful!!!";

    while(true){ //防止因为异常发生退出程序
        try{
            //读取配置
            bool is_enemy_red;
            string serial_path;
            cv::FileStorage f("../res/main_config.yaml", cv::FileStorage::READ);
            f["enemy_is_red"] >> is_enemy_red;
            f["serial_path"] >> serial_path;

            //创建黑板
            std::shared_ptr<Blackboard> blackboard_ptr = std::make_shared<Blackboard>();
            blackboard_ptr->init(is_enemy_red, serial_path);

            //创建监听线程并启动
            SerialListenThread serial_listen_thread;
            serial_listen_thread.init(blackboard_ptr);
            serial_listen_thread.start();
            LOG_INFO<<"serial listener has started!!!";

            //串口debug模块
            //SerialPortDebug serialPortDebug;
            //serialPortDebug.init(blackboard_ptr->getpSerialInterface());
            //serialPortDebug.testSerialPort();

            //测试行为树和发送数据
            //BehaviorTestTree behavior_test_tree(blackboard_ptr, 25);
            //behavior_test_tree.execute();

            //开启行为树
            SentryBehaviorTree sentry_behavior_tree(blackboard_ptr, 25);
            sentry_behavior_tree.execute(); //内部会有while堵塞

        } catch (...){
            LOG_ERROR<<"exceptions happened!!!";
        }

        usleep(5000000); //休眠5s尝试继续执行
    }
    return 0;
}