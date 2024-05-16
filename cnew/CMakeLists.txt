# add the directories containing the header files to the search path
include_directories(include)

# collect all source files from the src directory
set(SOURCES "main.cpp")

# create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# link against argparse
target_link_libraries(${PROJECT_NAME} argparse)
install(TARGETS ${PROJECT_NAME})
