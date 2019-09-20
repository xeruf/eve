cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(eve main.cpp Model/World/world.cpp Model/World/world.h Model/Food/food.cpp Model/Food/food.h)