cmake_minimum_required(VERSION 3.5)
project(sentry_autoaim)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(OpenCV 3.4.3 REQUIRED)
find_package(Glog REQUIRED)
#find_package(Halcon REQUIRED)

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GLOG_INCLUDE_DIR}
    #${HALCON_INCLUDE_DIR}
    #${HALCON_INCLUDE_DIR}/halconcpp
    
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/libHardWare/serialPort/include
    ${PROJECT_SOURCE_DIR}/libHardWare/usbCapture/include
    ${PROJECT_SOURCE_DIR}/libHardWare/mindVision/include
    ${PROJECT_SOURCE_DIR}/libBase/baseClasses/include
    ${PROJECT_SOURCE_DIR}/libBase/baseTools/include
    ${PROJECT_SOURCE_DIR}/libBT/include
    ${PROJECT_SOURCE_DIR}/libSentryAutoAim/include
    ${PROJECT_SOURCE_DIR}/libSentryAutoAim/include/test
)

add_subdirectory(${PROJECT_SOURCE_DIR}/libBase)
add_subdirectory(${PROJECT_SOURCE_DIR}/libHardWare)
add_subdirectory(${PROJECT_SOURCE_DIR}/libBT)
add_subdirectory(${PROJECT_SOURCE_DIR}/libSentryAutoAim)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

add_executable(kxjh ${DIR_SRCS})

target_link_libraries(kxjh
    SerialPort
    UsbCapture
    MindVision
    SentryAutoAim
    pthread
    BehaviorTree
    BaseClasses
    BaseTools
    MVSDK
    ${OpenCV_LIBS} #必须放在后面，否则报错
    ${GOLG_LIBRARY}
    #${HALCON_LIBRARY}
    #${HALCONCPP_LIBRARY}
)