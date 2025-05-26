#include <raylib.h>

#ifndef BOARD_H_
#define BOARD_H_

#define CELL_SIZE 120;

typedef struct {
	Rectangle pos;
	Color color;
	bool isHover;
} VBRC; //VisullBoardRepresentationCell

void InitBoard(int len, VBRC board[len][len], int sWidth, int cSize);
void DrawBoard(int len, VBRC board[len][len], Vector2 mPos);

#endif
