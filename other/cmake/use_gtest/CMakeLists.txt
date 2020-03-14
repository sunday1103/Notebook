cmake_minimum_required(VERSION 3.10)
project(use_gtest)

set(CMAKE_CXX_STANDARD 14)

add_executable(use_gtest main.cpp)

target_link_libraries(use_gtest gtest gtest_main pthread)