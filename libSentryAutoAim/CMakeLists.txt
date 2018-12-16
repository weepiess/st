include_directories(./include
                    ./include/actions
                    ./include/test)

aux_source_directory(./src SENTRY_SRCS)
aux_source_directory(./src/actions SENTRY_ACTIONS)
aux_source_directory(./src/test SENTRY_TEST)

add_library(SentryAutoAim ${SENTRY_SRCS} ${SENTRY_ACTIONS} ${SENTRY_TEST})

target_link_libraries(SentryAutoAim BehaviorTree BaseClasses BaseTools)