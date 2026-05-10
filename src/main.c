#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "../includes/renderer.h"
#include "../includes/utils.h"
#include "../includes/types.h"
#include "../includes/input.h"
#include "../includes/game.h"
#include "../includes/defs.h"
#include "../includes/menu.h"

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
    atexit(term_restore);
    fflush(stdout);
    cursor_hide();

    short running_menu = 1;
    short running_game = 0;

    Snake snake;
    Food  food;

    while (running_menu) {
    	int score = 0;
     	int lifes = 3;

        print_menu_title();
        print_menu_text();
        running_game = input_menu();
        clear_screen();

        if (running_game) {
            term_raw();

            snake_init(&snake);
            spawn_food(&food, &snake);
            score = 0;

            while (lifes > 0) {
                int key = read_key();

                if (key == 'q') { break; }

                if (key == KEY_SPACE) {
                    toggle_pause();
                    key = 0;
                }

                if (!is_paused()) {
                    if (key == UP    && snake.dir != DOWN ) { snake.dir = UP;    }
                    if (key == DOWN  && snake.dir != UP   ) { snake.dir = DOWN;  }
                    if (key == LEFT  && snake.dir != RIGHT) { snake.dir = LEFT;  }
                    if (key == RIGHT && snake.dir != LEFT ) { snake.dir = RIGHT; }

                    int result = snake_move(&snake, &food);

                    if (result == -1) {
                        lifes--;
                        if (lifes > 0) {
                        	draw(&snake, &food, score, lifes, 1);
                          	snake_init(&snake);
                           	sleep(2);
                        }
                    } else if (result == 1) {
                        snake.len++;
                        score += 10;
                        spawn_food(&food, &snake);
                    }
                }

                clear_screen();

                if (is_paused()) {
                	draw(&snake, &food, score, lifes, 1);
                    draw_pause();
                    fflush(stdout);
                    usleep(50000);
                } else {
                	draw(&snake, &food, score, lifes, 0);
                    usleep(1200);
                }

                usleep(120000);
            }

            clear_screen();
            printf("game over");
            sleep(2);
            clear_screen();
            running_game = 0;
            term_restore();
        }
    }

    return 0;
}
