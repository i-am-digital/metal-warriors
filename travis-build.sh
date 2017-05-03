#!/bin/bash

mkdir build
cd build
cmake .. -G"CodeBlocks - Unix Makefiles" && make
cd source
./metal-warriors
