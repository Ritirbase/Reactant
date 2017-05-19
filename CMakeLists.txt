cmake_minimum_required(VERSION 3.6)
project(clion_test)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c header/util.h src/util.c header/socket.h src/socket.c)
add_executable(clion_test ${SOURCE_FILES})


# Customized edits
include_directories(header)
include_directories(src)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")