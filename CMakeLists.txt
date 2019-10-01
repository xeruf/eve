
cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(
eve
src/model/object/object.h
src/model/object/object.cpp
src/model/object/entity/entity.cpp
src/model/object/entity/food/food.cpp
src/model/object/entity/food/food.h
src/model/object/entity/entity.h
src/model/object/entity/individual/individual.h
src/model/object/entity/individual/individual.cpp
src/model/model.h
src/model/world/world.cpp
src/model/world/world.h
src/model/model.cpp
src/main.h
src/main.cpp
src/controller/controller.h
src/controller/controller.cpp
)

add_executable(
tests
src/model/object/object.h
src/model/object/object.cpp
src/model/object/entity/entity.cpp
src/model/object/entity/food/food.cpp
src/model/object/entity/food/food.h
src/model/object/entity/entity.h
src/model/object/entity/individual/individual.h
src/model/object/entity/individual/individual.cpp
src/model/model.h
src/model/world/world.cpp
src/model/world/world.h
src/model/model.cpp
src/main.h
src/controller/controller.h
src/controller/controller.cpp
test/model/object/entity/food/food.cpp
test/model/world/world.cpp
test/main.cpp
)

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)