#!/usr/bin/env sh
mkdir -p cmake-build-debug
cmake -B cmake-build-debug
cmake --build cmake-build-debug --target tests
./tests
