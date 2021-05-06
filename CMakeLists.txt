cmake_minimum_required(VERSION 3.19)

project(game)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")


link_libraries(SDL2)
add_executable(game main.c interface.c model.c view.c)

add_executable(unit_tests unit_tests.c model.c unity.c)


install(TARGETS game RUNTIME DESTINATION bin)
