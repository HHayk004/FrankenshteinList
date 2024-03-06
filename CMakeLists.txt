cmake_minimum_required(VERSION 3.12)
project(prog CXX)
set(SOURCES
    ./main.cpp
)

add_executable(a.out ${SOURCES})

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # For GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # For Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # For MSVC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")
endif()