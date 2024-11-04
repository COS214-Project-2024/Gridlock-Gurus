# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Practical-6 VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include drectory for the header files and source files
include_directories(headers)
include_directories(src)
include_directories(tests)
include_directories(images)


file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/Main.cpp")  # Exclude Main.cpp
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/headers/*.h")


# Google Test Setup
add_subdirectory(googletest)
enable_testing()


# Add test executable (without Main.cpp)
add_executable(tests tests/government_tests.cpp tests/transport_test.cpp tests/tax_system_test.cpp tests/building_test.cpp tests/citizen_test.cpp ${SOURCE_FILES} ${HEADER_FILES})

# Add main application executable (with Main.cpp)
add_executable(main src/Main.cpp ${SOURCE_FILES} ${HEADER_FILES})


target_link_libraries(tests gtest gtest_main pthread)

# Link libraries based on the operating system
# if(WIN32)
target_link_libraries(main user32 gdi32 opengl32 gdiplus Shlwapi dwmapi stdc++fs)
# else()
    # target_link_libraries(main pthread stdc++fs)
# endif()

# Register tests with CTest
add_test(NAME all_tests COMMAND tests)

