cmake_minimum_required(VERSION 3.10)

project(game C)

set(CMAKE_C_STANDARD 11)

add_executable(game
    src/renderer.c
    src/input.c
    src/utils.c
    src/main.c
    src/game.c
    src/menu.c
    src/died.c
)
