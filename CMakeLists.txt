cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        eve
        src/main.cpp src/main.h
        src/model/object/object.cpp src/model/object/object.h
        src/model/world/world.cpp src/model/world/world.h
        src/model/object/food/food.cpp src/model/object/food/food.h src/model/model.h src/model/model.cpp src/controller/controller.cpp src/controller/controller.h src/model/object/entity/entity.cpp src/model/object/entity/entity.h test/controller/controller.cpp test/model/world/world.cpp)

add_executable(
        tests
        test/main.cpp
        test/model/object/food/food.cpp
        src/model/object/object.cpp src/model/object/object.h
        src/model/world/world.cpp src/model/world/world.h
        src/model/object/food/food.cpp src/model/object/food/food.h src/model/model.cpp src/controller/controller.cpp src/controller/controller.h src/model/object/entity/entity.cpp src/model/object/entity/entity.h test/controller/controller.cpp test/model/world/world.cpp)

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)