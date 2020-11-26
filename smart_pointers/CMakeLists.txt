cmake_minimum_required(VERSION 3.14)
project(smart_pointer)
add_executable(smart_pointer
    src/Functions.cpp
    src/examples/unique_ptr_examples.cpp
    src/examples/shared_ptr_examples.cpp)

target_include_directories(smart_pointer PUBLIC inc)
target_link_libraries(smart_pointer 
    PUBLIC entity 
    PUBLIC trace)