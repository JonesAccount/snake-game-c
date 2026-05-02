#ifndef GAME_H
#define GAME_H

#include "types.h"

void snake_init(Snake *snake);
int snake_move(Snake *s, const Food *food);
void spawn_food(Food *food, const Snake *snake);

#endif