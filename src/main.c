#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "renderer.h"
#include "utils.h"
#include "types.h"
#include "input.h"
#include "game.h"
#include "defs.h"

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	
	short running_menu = 1;
	short running_game = 1;
	
	Snake snake;
	Food  food;
	
	while (running_menu) {
		// - - - - - - - - - - - - - - - - - 
		term_raw();
		cursor_hide();
		clear_screen();

		snake_init(&snake);
		spawn_food(&food, &snake);

		int score = 0;
		// - - - - - - - - - - - - - - - - - 
		while (running_game) {
        	int key = read_key();
         	if (key == 'q') { break; }

          	if (key == UP    && snake.dir != DOWN ) { snake.dir = UP;    }
           	if (key == DOWN  && snake.dir != UP   ) { snake.dir = DOWN;  }
            if (key == LEFT  && snake.dir != RIGHT) { snake.dir = LEFT;  }
           	if (key == RIGHT && snake.dir != LEFT ) { snake.dir = RIGHT; }

            int result = snake_move(&snake, &food);

            if (result == -1) {
           		running_game = 0;
            } else if (result == 1) {
           		snake.len++;
            	score += 10;
            	spawn_food(&food, &snake);
            }

            draw(&snake, &food, score);
            usleep(200000); // 120000
    	}
		running_menu = 0;
	}

	clear_screen();
	cursor_show();
	term_restore();
	printf("Game over!");
	return 0;
}
