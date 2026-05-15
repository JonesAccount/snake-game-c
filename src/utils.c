#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "../includes/utils.h"

struct termios orig_term;

void term_raw(void) {
	struct termios t;
	tcgetattr(STDIN_FILENO, &orig_term);
	t = orig_term;
	t.c_lflag &= ~(ICANON | ECHO);
	t.c_cc[VMIN]  = 0;
	t.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void term_restore(void) {
	tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN]  = 1;  
    newt.c_cc[VTIME] = 0;  
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void clear_buff(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen(void) {
	fputs("\033[2J\033[H", stdout);
	fflush(stdout);
}

void move_cursor(int x, int y) {
	printf("\033[%d;%dH", y + 1, x * 2 + 1);
}

void cursor_hide(void) { printf("\033[?25l"); }
void cursor_show(void) { printf("\033[?25h"); }
