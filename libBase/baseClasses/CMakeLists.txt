include_directories(./include)

aux_source_directory(./src BASECLASSES_SRCS)
add_library(BaseClasses ${BASECLASSES_SRCS})
