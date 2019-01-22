cmake_minimum_required (VERSION 2.8)

project(yam-cat)

add_executable(yam-cat.out yam-cat.c)

install(TARGETS yam-cat.out RUNTIME DESTINATION bin)
