#ifndef FIGURE_H_
#define FIGURE_H_

#include <stdbool.h>
enum FigureType {
	PAWN = 1,
	ROOK,
	BISHOP,
	KNIGHT,
	QUEEN,
	KING
};

enum Team {
	W = 1,
	B
};

#endif
