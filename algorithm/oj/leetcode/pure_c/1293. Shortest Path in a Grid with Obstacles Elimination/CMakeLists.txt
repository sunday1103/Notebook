# cmake_minimum_required(VERSION <specify CMake version here>)
project(1293__Shortest_Path_in_a_Grid_with_Obstacles_Elimination C)

set(CMAKE_C_STANDARD 99)
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
add_executable(1293__Shortest_Path_in_a_Grid_with_Obstacles_Elimination main.c)