#!/bin/sh

f () {
	find $1 -name '*.h' -or -name '*.hpp' -or -name '*.cpp' | grep -v $2
}

###
echo "
cmake_minimum_required(VERSION 3.14)
project(eve)

set(CMAKE_CXX_STANDARD 17)

add_executable(
eve"
###
f "src" "@"
###
echo ")

add_executable(
tests"
###
f "src" "src/main.cpp"
f "test" "@"
###
echo ")

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)
"
###

