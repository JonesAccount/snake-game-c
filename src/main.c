#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "renderer.h"
#include "game.h"
#include "defs.h"

typedef struct {
    int x, y;
} Snake;

Snake snake[(MAP_Y - 2) * (MAP_X - 3)];

typedef struct {
	int x, y;
} Food;

Food food;

int main(int argc, char *argv[]) {
	printf("\033[?25l");
	srand(time(NULL));

	snake_init(&snake);
	
	while (1) {
        fill_map();
        render_map();
        (void)getchar();
    }

    printf("\033[?25h");
	return 0;
}
