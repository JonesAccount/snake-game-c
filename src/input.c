#include <unistd.h>

#include "../includes/input.h"
#include "../includes/defs.h"

int read_key(void) {
	char buf[4] = {0};
	int n = read(STDIN_FILENO, buf, sizeof(buf));
	if (n <= 0) { return 0; }
	
	if (buf[0] == 'q' || buf[0] == 'Q') { return 'q';   }  
	if (buf[0] == 'w' || buf[0] == 'W') { return UP;    }
	if (buf[0] == 's' || buf[0] == 'S') { return DOWN;  }
	if (buf[0] == 'a' || buf[0] == 'A') { return LEFT;  }
	if (buf[0] == 'd' || buf[0] == 'D') { return RIGHT; }
	
	if (n >= 3 && buf[0] == '\033' && buf[1] == '[') {
		if (buf[2] == 'A') { return UP;    }
		if (buf[2] == 'B') { return DOWN;  }
		if (buf[2] == 'C') { return RIGHT; }
		if (buf[2] == 'D') { return LEFT;  }
	}
	
	return 0;
}