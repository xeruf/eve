cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(eve src/main.cpp src/main.h src/model/world/world.cpp src/model/world/world.h src/model/food/food.cpp src/model/food/food.h)