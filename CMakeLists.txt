cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(eve main.cpp test.cpp test.h world.cpp world.h food.cpp food.h)