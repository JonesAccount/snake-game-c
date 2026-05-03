#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "../include/renderer.h"
#include "../include/utils.h"
#include "../include/types.h"
#include "../include/input.h"
#include "../include/game.h"
#include "../include/defs.h"
#include "../include/menu.h"

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));

	short running_menu = 1;
	short running_game = 0;

	Snake snake;
	Food  food;
	
	int score = 0;

	while (running_menu) {
		clear_screen();
		term_restore();
		cursor_show();
		
		print_menu_title();
		print_menu_text();
		running_game = input_menu();
		clear_screen();
		
		if (running_game) {
			term_raw();
			cursor_hide();
			
			snake_init(&snake);
			spawn_food(&food, &snake);
			score = 0;
		
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
	            usleep(120000); 
	    	}
		}
	}
	
	return 0;
}
