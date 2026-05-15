#ifndef GAME_H
#define GAME_H

#include "types.h"

void toggle_pause(void);
int is_paused(void);
void snake_init(Snake *snake);
int snake_move(Snake *s, const Food *food);
void draw_pause(void);
void spawn_food(Food *food, const Snake *snake);

#endif