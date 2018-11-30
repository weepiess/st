include_directories(./include)

aux_source_directory(./src BASETOOLS_SRCS)
add_library(BaseTools ${BASETOOLS_SRCS})
target_link_libraries(BaseTools ${GLOG_LIBRARY})