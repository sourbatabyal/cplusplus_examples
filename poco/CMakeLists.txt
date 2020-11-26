cmake_minimum_required(VERSION 3.14)
project(entity)
add_library(entity src/Entity.cpp)
target_include_directories(entity PUBLIC inc)