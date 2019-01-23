#!/bin/bash

cd build
cmake .. -DCMAKE_INSTALL_PREFIX=.. 
#-DBUILD_SHARED_LIBS=ON
make
make install
