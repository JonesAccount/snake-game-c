#ifndef UTILS_H
#define UTILS_H

void term_raw(void);
void term_restore(void);
void clear_screen(void);
void move_cursor(int x, int y);
void cursor_hide(void);
void cursor_show(void);

#endif