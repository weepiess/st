include(FindPackageHandleStandardArgs)

set(HALCON_ROOT_DIR "/opt/halcon")

find_path(HALCON_INCLUDE_DIR Halcon.h
        PATHS ${HALCON_ROOT_DIR}/include/)

find_library(HALCON_LIBRARY halcon
        PATHS ${HALCON_ROOT_DIR}/lib/x64-linux/
        PATH_SUFFIXES lib lib64)

find_library(HALCONCPP_LIBRARY halconcpp
        PATHS ${HALCON_ROOT_DIR}/lib/x64-linux/
        PATH_SUFFIXES lib lib64)

find_package_handle_standard_args(HALCON DEFAULT_MSG HALCON_INCLUDE_DIR HALCON_LIBRARY)

if(HALCON_FOUND)
    message(STATUS "Found Halcon (include: ${HALCON_INCLUDE_DIR}, 
                                library: ${HALCON_LIBRARY}
                                cpplibrary: ${HALCONCPP_LIBRARY})")
    mark_as_advanced(HALCON_ROOT_DIR HALCON_LIBRARY_RELEASE HALCON_LIBRARY_DEBUG
                                 HALCON_LIBRARY HALCONCPP_LIBRARY HALCON_INCLUDE_DIR)
endif()