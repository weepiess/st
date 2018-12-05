cmake_minimum_required(VERSION 3.5)

project(sentry_autoaim)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
SET(OpenCV_DIR /usr/local/opencv3/share/OpenCV)
find_package(OpenCV 3.4.3 REQUIRED)
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/libHardWare/serialPort/include)
include_directories(${PROJECT_SOURCE_DIR}/libHardWare/usbCapture/include)
include_directories(${PROJECT_SOURCE_DIR}/libHardWare/mindVision/include)
include_directories(${PROJECT_SOURCE_DIR}/libBase/baseTools/include)
include_directories(${PROJECT_SOURCE_DIR}/libBase/baseClasses/include)
include_directories(${PROJECT_SOURCE_DIR}/libHardWare/usbCapture/include)
include_directories(${PROJECT_SOURCE_DIR}/libAim/autoAim/include)
include_directories(${PROJECT_SOURCE_DIR}/libAim/markAim/include)
include_directories(${PROJECT_SOURCE_DIR}/libBT/include)
include_directories(${PROJECT_SOURCE_DIR}/libSentryAutoAim/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/libHardWare)
add_subdirectory(${PROJECT_SOURCE_DIR}/libBase)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/libAim)
add_subdirectory(${PROJECT_SOURCE_DIR}/libBT)
add_subdirectory(${PROJECT_SOURCE_DIR}/libSentryAutoAim)


aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

add_executable(kxjh ${DIR_SRCS})

target_link_libraries(kxjh SerialPort UsbCapture)
target_link_libraries(kxjh MindVision)
target_link_libraries(kxjh pthread)
target_link_libraries(kxjh AutoAim MarkAim)
target_link_libraries(kxjh BaseTools BaseClasses)

target_link_libraries(kxjh SentryAutoAim BehaviorTree)
target_link_libraries(kxjh MVSDK)  


target_link_libraries(kxjh ${GOLG_LIBRARY})
target_link_libraries(kxjh ${OpenCV_LIBS})  

     #必须放在后面，否则报错
    
