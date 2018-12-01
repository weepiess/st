include_directories(./include)

AUX_SOURCE_DIRECTORY(./src SENTRY_SRCS)
ADD_LIBRARY(SentryAutoAim ${SENTRY_SRCS})
target_link_libraries(BehaviorTree)