#!/bin/bash

mkdir build
cd build
cmake -G"CodeBlocks - Unix Makefiles" -DCMAKE_CXX_COMPILER=g++-6 .. && make
cd tests
./metal-warriors.tests
