#ifndef GAME_H
#define GAME_H

void snake_init(Snake *snake);
void snake_move(void);
void snake_grow(void);
void snake_is_dead(void); 
void food_spawn(void);
void food_is_eaten(void);

#endif