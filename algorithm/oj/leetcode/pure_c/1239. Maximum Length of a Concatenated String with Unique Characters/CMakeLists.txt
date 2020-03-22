cmake_minimum_required(VERSION 3.10)
project(1239__Maximum_Length_of_a_Concatenated_String_with_Unique_Characters C)

set(CMAKE_C_STANDARD 99)
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
add_executable(1239__Maximum_Length_of_a_Concatenated_String_with_Unique_Characters main.c)