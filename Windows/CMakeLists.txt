cmake_minimum_required(VERSION 3.10)
project(MyProject C)  # Replace "MyProject" with your project name

# Set C standard
set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Source files
set(SOURCE_FILES
    src/main.c
    lib/checker.c
    lib/cJSON.c
    lib/hxh.c
    lib/leaderboard.c
    lib/mylib.c
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Set the output directory for Visual Studio
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
