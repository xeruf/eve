cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-lSDL2 -lSDL2_gfx")
execute_process(COMMAND cat /etc/os-release
        OUTPUT_VARIABLE OS_INFO)
if("${OS_INFO}" MATCHES "buntu")
    message("Running on Ubuntu - manually linking SDL2!")
    set(UBUNTU 1)
endif()

if(UBUNTU)
    set(SDL2_DIR /usr/lib/x86_64-linux-gnu/cmake/SDL2)
    set(LIB_SDL2 /usr/lib/x86_64-linux-gnu/libSDL2.so /usr/lib/x86_64-linux-gnu/libSDL2_gfx.so)
endif()

find_package(SDL2 REQUIRED)

project(eve)
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*/*.cpp)
add_executable(eve src/main.cpp ${SRCS})

if(UBUNTU)
    target_link_libraries(eve ${LIB_SDL2})
endif()

find_package(Catch2)
IF (Catch2_FOUND)
    file(GLOB_RECURSE TEST_SRCS ${PROJECT_SOURCE_DIR}/test/*.c*)
    add_executable(tests ${TEST_SRCS} ${SRCS})

    add_compile_definitions(tests ERRORS_AS_WARNINGS)

    target_link_libraries(tests Catch2::Catch2)
    include(CTest)
    include(Catch)
    catch_discover_tests(tests)
ENDIF()
