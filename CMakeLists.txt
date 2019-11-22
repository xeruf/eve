cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-lSDL2 -lSDL2_gfx")

project(eve)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*/*.cpp)
file(GLOB_RECURSE TEST_SRCS ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_executable(eve src/main.cpp ${SRCS})

add_executable(tests ${TEST_SRCS} ${SRCS})
find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)
include(CTest)
include(Catch)
catch_discover_tests(tests)
