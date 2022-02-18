# This is the top-level CMakeLists.txt file

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(cpp_assignment CXX)

# C++ standard specification
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TESTS "Build assignment tests." ON)
option(ENABLE_COMPILER_WARNINGS "Project compile warnings." ON)

# Library
add_library(${PROJECT_NAME} STATIC src/code.cpp include/assignment/code.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

# Warnings
if (ENABLE_COMPILER_WARNINGS)
    add_library(project_warnings INTERFACE)

    include(cmake/CompilerWarnings.cmake)
    set_project_warnings(project_warnings)

    target_link_libraries(${PROJECT_NAME} PUBLIC project_warnings)

endif (ENABLE_COMPILER_WARNINGS)

# Executables
add_executable(run_${PROJECT_NAME} main.cpp)

target_link_libraries(run_${PROJECT_NAME} PRIVATE ${PROJECT_NAME})

# Tests
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(contrib)
    add_subdirectory(tests)
endif (BUILD_TESTS)
