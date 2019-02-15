#!/bin/bash

cd build
make
make install
cd ../bin
printf "Runnning Program: \n\n"
./YAMBASIC.out
