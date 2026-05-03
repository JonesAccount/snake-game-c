#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "../include/utils.h"
#include "../include/defs.h"

const char *title[] = {
	"                                      88                            ",
	"                                      88                            ",
	"                                      88                            ",
	" __  ,adPPYba, 8b,dPPYba,  ,adPPYYba, 88   ,d8  ,adPPYba,           ",
	"{OO} I8[      "" 88P'   `\"8a ""       `Y8 88 ,a8\"  a8P_____88     ",
	"\\__/  `\"Y8ba,  88       88 ,adPPPPP88 8888[    8PP""""""\"        ",
	" |^| aa    ]8I 88       88 88,    ,88 88`\"Yba, \"8b,   ,aa         ",
	" |^| `\"YbbdP\"' 88       88 `\"8bbdP\"Y8 88   `Y8a `\"Ybbd8\"'  /\\",
	" | |______________________________________________________/ /       ",
	" \\_________________________________________________________/       "
	};

char *options[] = {" PLAY", "RECORD", "OPTION", " EXIT"};

typedef struct { unsigned int x:2; } St;
St st = {0};

int input_menu(void) {
	char ch = tolower(getch());

	switch (ch) {
		case 'w': st.x--; break;
		case 's': st.x++; break;
		case 10:
		case 13:
			switch (st.x) {
				case 0: return 1;
				case 1: break;
				case 2: break;
				case 3: 
					cursor_show();
					term_restore();
					clear_screen();
					exit(0);
			}
	}

	return 0;
}

void print_menu_title(void) {
	clear_screen();
	for (int i = 0; i < 10; i++) {
		if (!i) { printf(NLINE NLINE); }
		printf(TAB TAB "%s" NLINE, *(title + i));
	}
}

void print_menu_text(void) {
	printf(BOLD "\033[16;37H%s", (st.x == 0) ? "➤ " : "");
	printf("\033[16;40H%s" RESET, *options);

	printf(BOLD "\033[18;37H%s", (st.x == 1) ? "➤ " : "");
	printf("\033[18;40H%s" RESET, *(options + 1));

	printf(BOLD "\033[20;37H%s", (st.x == 2) ? "➤ " : "");
	printf("\033[20;40H%s" RESET, *(options + 2));

	printf(BOLD "\033[22;37H%s", (st.x == 3) ? "➤ " : "");
	printf("\033[22;40H%s" RESET, *(options + 3));

	fflush(stdout);
}
