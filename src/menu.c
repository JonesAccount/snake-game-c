#include <stdio.h>

#include "../include/utils.h"
#include "../include/defs.h"
#include "../include/input.h"

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

typedef struct { unsigned int x:3; } Choice;
Choice choice = {0};

void print_title(void) {
	clear_screen();
	for (int i = 0; i < 10; i++) {
		if (!i) { printf(NLINE NLINE); }
		printf(TAB TAB "%s" NLINE, *(title + i));
	}
}

void print_menu_text(void) {
	for (int i = 0; i < 4; i++) {
		printf(NLINE);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) { printf(TAB); }
		if (!i) { printf("%s", "➤"); }
		printf(BOLD "%s" NLINE NLINE, *(options + i));

		switch (choice.x) {
			case 0: printf(BOLD "%s" NLINE NLINE, *options); break;
		}
	}
}

int render_menu(void) {
	print_title();
	print_menu_text();

	read_key();
	return 1;
}




/*
             ____
            / . .\
            \  ---<
             \  /
   __________/ /
-=:___________/


						 ____
________________________/ O  \___/
<_O_O_O_O_O_O_O_O_O_O_O_O_____/  \


					  __    __    __    __
					 /  \  /  \  /  \  /  \
____________________/  __\/  __\/  __\/  __\_____________________________
___________________/  /__/  /__/  /__/  /________________________________
				  | / \   / \   / \   / \  \____
				  |/   \_/   \_/   \_/   \    o \
                                          \_____/--<


                                          88
                                          88
                                          88
         ,adPPYba, 8b,dPPYba,  ,adPPYYba, 88   ,d8  ,adPPYba,
         I8[    "" 88P'   `"8a ""     `Y8 88 ,a8"  a8P_____88
          `"Y8ba,  88       88 ,adPPPPP88 8888[    8PP"""""""
         aa    ]8I 88       88 88,    ,88 88`"Yba, "8b,   ,aa
         `"YbbdP"' 88       88 `"8bbdP"Y8 88   `Y8a `"Ybbd8"'




         		 				          88
         							      88
                  						  88
    __   ,adPPYba, 8b,dPPYba,  ,adPPYYba, 88   ,d8  ,adPPYba,
   {OO}  I8[    "" 88P'   `"8a ""     `Y8 88 ,a8"  a8P_____88
   \__/  `"Y8ba,   88       88 ,adPPPPP88 8888[    8PP"""""""
    |^|  aa    ]8I 88       88 88,    ,88 88`"Yba, "8b,   ,aa
    |^|  `"YbbdP"' 88       88 `"8bbdP"Y8 88   `Y8a `"Ybbd8"' /\
    | |______________________________________________________/ /
    \_________________________________________________________/


    		  __
             {OO}
             \__/
              |^|                                             /\
              | |____________________________________________/ /
              \_______________________________________________/





         A Classic ASCII Snake Game
         The Snake game is one of the earliest, most addictive arcade video games, dating back to the 1970s. The mechanic of the game is very simple yet addictive: a growing line that collects apples, where the player must avoid collisions with the snake's body or the border. This game was perfectly suited for early computers and consoles with their simple text and block graphics, making it a natural fit for the ASCII Art format you see here.
         Our ASCII Snake Game is a rebuild of the original game that honors that retro simplicity, using ASCII characters for the snake body and game borders to provide a deeply nostalgic experience. By keeping the graphics to the bare minimum ASCII text on a screen, we stay true to the game's roots.
         Controls and How to Play
         Move: Use the Arrow Keys (Up, Down, Left, Right) on the keyboard or use the on-screen control buttons.
         Mobile: Use the on-screen control buttons.
         Objective: Move the snake to eat the apples and avoid collisions.
         Game Over: The game ends when the snake hits the wall or collides with its own body.
         Speed: The game speeds up as your snake eats apples.

         ______
    _.-""      ""-._
 .-'                `-.
.'      __.----.__      `.
/     .-"          "-.     \
/    .'                `.    \
J    /                    \    L
F   J                      L   J
J    F                      J    L
|   J                        L   |
|   |                        |   |
|   J                        F   |
J    L                      J    F
L   J   .-""""-.           F   J
J    \ /        \   __    /    F
\    (|)(|)_   .-'".'  .'    /
\    \   /_>-'  .<_.-'     /
`.   `-'     .'         .'
 `--.|___.-'`._    _.-'
     ^         """"

     ____
_,.-'`_ o `;__,                cjr
_.-'` '---'  '

*/
