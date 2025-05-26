#include <raylib.h>

#ifndef BOARD_H_
#define BOARD_H_

#define CELL_SIZE 120;

typedef struct {
	Rectangle pos;
	Color color;
	bool isHover;
} VBCR; //VisullBoardRepresentationCell

void InitBoard(int len, VBCR board[len][len], int sWidth, int cSize);
void DrawCell(VBCR cell);

#endif
