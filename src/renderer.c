#include <stddef.h>
#include <stdio.h>

#include "renderer.h"
#include "defs.h"

char map[MAP_Y * MAP_X];

void fill_map(void) {
    for (size_t i = 0; i < MAP_Y; i++) {
        for (size_t j = 0; j < MAP_X; j++) {
            if (i == 0 || i == MAP_Y - 1 || j == 0 || j == MAP_X - 1) {
                map[i * MAP_X + j] = '#';
            } else {
                map[i * MAP_X + j] = ' ';
            }
        }
    }
}

void render_map(void) {
    for (size_t i = 0; i < MAP_SIZE; i++) {
        printf("%c", map[i]);
        if ((i + 1) % MAP_X == 0) { printf("\n"); }
    }
}

void render_snake(void) {
	map[snake[0] -> y * MAP_X + snake[0] -> x] = '@';
}

void render_food(void) {
	
}

void render_score(void) {
	
}