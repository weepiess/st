include_directories(./include)
AUX_SOURCE_DIRECTORY(./src USBCAPTURE_DIR_SRCS)
ADD_LIBRARY(UsbCapture ${USBCAPTURE_DIR_SRCS})

target_link_libraries(UsbCapture BaseClasses)