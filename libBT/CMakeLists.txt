include_directories(./include)
aux_source_directory(./src BT_SRCS)
add_library(BehaviorTree ${BT_SRCS})

target_link_libraries(BehaviorTree
    BaseTools
    BaseClasses
    SerialPort
    UsbCapture
    MindVision
)