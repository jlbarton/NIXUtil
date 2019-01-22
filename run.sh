#!/bin/bash

cd build
make
make install
cd ../bin
./yam-cat.out
