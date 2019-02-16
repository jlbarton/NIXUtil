cmake_minimum_required (VERSION 2.8)
project(YAMBASIC)

include_directories(include/)
set(SOURCES yambasic.cpp scanner.cpp token.cpp)
set(HEADERS include/yambasic.h include/scanner.h include/token.h)


add_executable(YAMBASIC.out ${SOURCES} ${HEADERS})

install(TARGETS YAMBASIC.out RUNTIME DESTINATION bin)
