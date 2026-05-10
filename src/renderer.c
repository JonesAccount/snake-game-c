#include <string.h>
#include <stdio.h>

#include "../includes/renderer.h"
#include "../includes/utils.h"
#include "../includes/defs.h"

void draw(const Snake *s, const Food *food, int score, int lifes, int is_paused) {
	const char *color = is_paused ? GRAY : "";
	char field[HEIGHT][WIDTH];
	memset(field, ' ', sizeof(field));

	for (int i = 0; i < s -> len; i++) {
		field[s -> body[i].y][s -> body[i].x] = (i == 0) ? '@' : 'o';
	}

	field[food -> pos.y][food -> pos.x] = '*';

	move_cursor(0, 0);

	if (is_paused) { printf(GRAY); }

	printf(BOLD);

	for (int x = 0; x < (WIDTH + 1) * 2; x++) { printf("#"); }
	printf("\n");

	for (int y = 0; y < HEIGHT; y++) {
		printf("%s#", (is_paused) ? GRAY : "");
		for (int x = 0; x < WIDTH; x++) {
			if (field[y][x] == '*') {
				printf(YELLOW "%s%c " RESET, (is_paused) ? GRAY : "", field[y][x]);
			} else {
				printf("%s%c ", (is_paused) ? GRAY : "", field[y][x]);
			}
		}
		printf("%s#" NLINE, (is_paused) ? GRAY : "");
	}

	for (int x = 0; x < (WIDTH + 1) * 2; x++) { printf("#"); }

	// infomation panel
	printf(BOLD "\033[23;6H%sSCORE:"      RESET, color);
	printf(BOLD "\033[23;31H%s%d"         RESET, color, score);
	printf(BOLD "\033[23;51H%sLEVEL:"     RESET, color);
	printf(BOLD "\033[23;76H%s%d"         RESET, color, 1);
	printf(BOLD "\033[25;6H%sBEST SCORE:" RESET, color);
	printf(BOLD "\033[25;31H%s%d"         RESET, color, 1555);
	printf(BOLD "\033[25;51H%sLIFE:"      RESET, color);
	printf(BOLD "\033[25;76H%s", (is_paused) ? GRAY : RED);
	for (int i = 0; i < lifes; i++) { printf("o"); }
	printf(RESET);
	
	fflush(stdout);
}
