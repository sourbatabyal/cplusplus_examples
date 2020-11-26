cmake_minimum_required(VERSION 3.14)
project(trace)
add_library(trace src/TraceMe.cpp)
target_include_directories(trace PUBLIC inc)