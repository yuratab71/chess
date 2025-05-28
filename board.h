#include <raylib.h>
#include "textures.h"

#ifndef BOARD_H_
#define BOARD_H_

#define CELL_SIZE 120;

/**
 * @struct BoardPosition
 * @brief Represents position on board
 *
 * v - vertical position
 * h - horizontal position
 */
typedef struct {
	int v;
	int h;
} BP; 

/**
* @struct BC
* @brief Repsents a cell on game board
*/
typedef struct {
	Rectangle pos;
	Color color;
	bool isHover;
	BP bp;
	int figure;
	int side;
} BC; // BoardCell

void InitBoard(int len, BC board[len][len], int sWidth, int cSize);
void InitBoardFigures(int len, BC board[len][len], int pSide);
void DrawCell(BC *cell);
void DrawFigure(BC *cell, FT *ft, float scale);

#endif
