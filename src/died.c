#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "../includes/utils.h"
#include "../includes/defs.h"

char *died_options[] = {"PLAY AGAIN", "MENU"};

bool select = true;

int input_died(void) {
	char ch = tolower(getch());

	switch (ch) {
		case 'w': select = true;  break;
		case 's': select = false; break;
		case 10:
		case 13:
			if (select) {
				return 1;
			} else {
				return 2;
			}
	}
	return 0;
}

void draw_died_text(void) {
	// clear selections
	printf("\033[%d;%dH ", HEIGHT/2, WIDTH/2 + 13);
    printf("\033[%d;%dH ", HEIGHT/2 + 2, WIDTH/2 + 13);
    
	printf(BOLD "\033[%d;%dHG A M E  O V E R!", HEIGHT/2 - 3, WIDTH/2 + 13);
    printf(BOLD "\033[%d;%dH%s" RESET, HEIGHT/2, WIDTH/2 + 13, (select) ? "➤ " : "");
    printf(BOLD "\033[%d;%dHPLAY AGAIN" RESET, HEIGHT/2, WIDTH/2 + 16);
    printf(BOLD "\033[%d;%dH%s" RESET, HEIGHT/2 + 2, WIDTH/2 + 13, (!select) ? "➤ " : "");
    printf(BOLD "\033[%d;%dHBACK TO MENU" RESET, HEIGHT/2 + 2, WIDTH/2 + 15);
}
