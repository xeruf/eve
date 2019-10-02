cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        eve
        src/main.cpp src/main.h
        src/model/object/entity/entity.cpp src/model/object/entity/entity.h
        src/model/world/world.cpp src/model/world/world.h
        src/model/object/entity/food/food.cpp src/model/object/entity/food/food.h src/model/model.h src/model/model.cpp src/controller/controller.cpp src/controller/controller.h src/model/object/entity/individual/individual.cpp src/model/object/entity/individual/individual.h src/model/object/obstacle/obstacle.cpp src/model/object/obstacle/obstacle.h src/model/object/object.cpp src/model/object/object.h src/model/geometry/shape/shape.cpp src/model/geometry/shape/shape.h src/model/geometry/line/line.cpp src/model/geometry/line/line.h)

add_executable(
        tests
        test/main.cpp
        test/model/object/entity/food/food.cpp
        src/model/object/entity/entity.cpp src/model/object/entity/entity.h
        src/model/world/world.cpp src/model/world/world.h
        src/model/object/entity/food/food.cpp src/model/object/entity/food/food.h src/model/model.cpp src/controller/controller.cpp src/controller/controller.h src/model/object/entity/individual/individual.cpp src/model/object/entity/individual/individual.h test/controller/controller.cpp test/model/world/world.cpp src/model/object/obstacle/obstacle.cpp src/model/object/obstacle/obstacle.h src/model/object/object.cpp src/model/object/object.h src/model/geometry/shape/shape.cpp src/model/geometry/shape/shape.h src/model/geometry/line/line.cpp src/model/geometry/line/line.h)

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)