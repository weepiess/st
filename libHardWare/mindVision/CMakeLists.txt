include_directories(./include)
AUX_SOURCE_DIRECTORY(./src MINDVISION_SRCS)
ADD_LIBRARY(MindVision ${MINDVISION_SRCS})
target_link_libraries(MindVision BaseClasses BaseTools MVSDK)