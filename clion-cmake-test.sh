#!/usr/bin/env sh
mkdir -p cmake-build-debug && cd cmake-build-debug
cmake ..
cmake --build . --target tests
./tests