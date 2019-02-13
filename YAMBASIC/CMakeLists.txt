cmake_minimum_required (VERSION 2.8)

project(YAMBASIC)

add_executable(YAMBASIC.out yambasic.c)

install(TARGETS YAMBASIC.out RUNTIME DESTINATION bin)
