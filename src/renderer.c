#include <string.h>
#include <stdio.h>

#include "renderer.h"
#include "utils.h"
#include "defs.h"

void draw(const Snake *s, const Food *food, int score) {
	char field[HEIGHT][WIDTH];
	memset(field, ' ', sizeof(field));
	
	for (int i = 0; i < s -> len; i++) {
		field[s -> body[i].y][s -> body[i].x] = (i == 0) ? '@' : 'o';
	} 
	
	field[food -> pos.y][food -> pos.x] = '*';
	
	move_cursor(0, 0);
	printf("+");
	for (int x = 0; x < WIDTH; x++) { printf("--"); }
	printf("+\n");
	
	for (int y = 0; y < HEIGHT; y++) {
		printf("|");
		for (int x = 0; x < WIDTH; x++) { printf("%c ", field[y][x]); }
		printf("|\n");
	}
	
	printf("+");
	for (int x = 0; x < WIDTH; x++) { printf("--"); }
	printf("+\n");
	printf("  Score: %d   (WASD / arrows = move, q = quit)\n", score);
	
	fflush(stdout);
}