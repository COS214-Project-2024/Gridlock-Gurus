# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Practical-6 VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include includes idrectory for the header files
include_directories(headers)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/headers/*.h")

# Add the main executable and specify all source files required
# Only main.cpp will act as the entry point

# Google Test Setup
# Assuming you've cloned Google Test in the googletest/ directory
add_subdirectory(googletest)
enable_testing()

# Add test executable
add_executable(tests tests/tax_system_test.cpp tests/building_test.cpp tests/citizen_test.cpp ${SOURCE_FILES} ${HEADER_FILES})
add_executable(main src/Main.cpp ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(tests gtest gtest_main pthread)

# Register tests with CTest
add_test(NAME all_tests COMMAND tests)

