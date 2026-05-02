#include <stdlib.h>

#include "types.h"
#include "defs.h"
#include "game.h"

void snake_init(Snake *s) {
	s -> len = 3;
	s -> dir = RIGHT;
	s -> body[0] = (Point){WIDTH / 2,     HEIGHT / 2};
	s -> body[1] = (Point){WIDTH / 2 - 1, HEIGHT / 2};
	s -> body[2] = (Point){WIDTH / 2 - 2, HEIGHT / 2};
}

int snake_move(Snake *s, const Food *food) {
	for (int i = s -> len - 1; i > 0; i--) {
		s -> body[i] = s -> body[i - 1];
	}
	
	Point *head = &s -> body[0];
	if (s -> dir == UP)    { head -> y--; }
	if (s -> dir == DOWN)  { head -> y++; }
	if (s -> dir == LEFT)  { head -> x--; }
	if (s -> dir == RIGHT) { head -> x++; }
	
	if (head -> x < 0 || head -> x >= WIDTH ||
		head -> y < 0 || head -> y >= HEIGHT) { return -1; }
	
	for (int i = 1; i < s -> len; i++) {
		if (s -> body[i].x == head -> x &&
			s -> body[i].y == head -> y) { return -1; }
	}
	
	if (head -> x == food -> pos.x &&
		head -> y == food -> pos.y) {
		s -> body[s -> len] = s -> body[s -> len - 1];
		return 1;
	}
	
	return 0;
}

void spawn_food(Food *food, const Snake *snake) {
	int ok;
	do {
		ok = 1;
		food -> pos.x = rand() % WIDTH;
		food -> pos.y = rand() % HEIGHT;
		for (int i = 0; i < snake -> len; i++) {
			if (snake -> body[i].x == food -> pos.x &&
				snake -> body[i].y == food -> pos.y) { ok = 0; break; }
		}
	} while (!ok);
}