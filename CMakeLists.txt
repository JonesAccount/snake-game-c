cmake_minimum_required(VERSION 3.10)

project(game C)

set(CMAKE_C_STANDARD 99)

add_executable(game
    src/main.c
    src/game.c
    src/input.c
    src/menu.c
    src/renderer.c
    src/utils.c
)