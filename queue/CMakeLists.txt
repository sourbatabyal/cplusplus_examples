cmake_minimum_required(VERSION 3.14)
project(queue)
add_executable(queue
    src/queue.cpp
    src/main.cpp)
target_include_directories(queue PUBLIC inc)
target_link_libraries(queue 
    PUBLIC entity 
    PUBLIC trace)