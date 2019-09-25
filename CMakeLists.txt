cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        eve
        src/main.cpp src/main.h
        src/model/world/world.cpp src/model/world/world.h
        src/model/food/food.cpp src/model/food/food.h
)

add_executable(
        tests
        test/main.cpp
        test/model/food/food.cpp
        src/model/world/world.cpp src/model/world/world.h
        src/model/food/food.cpp src/model/food/food.h
)

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)