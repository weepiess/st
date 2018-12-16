include_directories(./include 
                    ./include/test 
                    ./include/actions)

aux_source_directory(./src SENTRY_SRCS)
aux_source_directory(./src/test SENTRY_TEST)
aux_source_directory(./src/actions SENTRY_ACTIONS)

add_library(SentryAutoAim ${SENTRY_SRCS} ${SENTRY_TEST} ${SENTRY_ACTIONS})
target_link_libraries(SentryAutoAim BehaviorTree BaseClasses BaseTools)