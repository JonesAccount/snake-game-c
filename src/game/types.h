#ifndef TYPES_H
#define TYPES_H

#include "defs.h"

typedef struct { int x, y; } Point;

typedef struct {
	Point body[MAX_LEN];
	int   len;
	int   dir;
} Snake;

typedef struct {
	Point pos;
} Food;

#endif
