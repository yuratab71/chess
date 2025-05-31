#include <raylib.h>
#include "bitboard.h"
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
* @brief Repsents a visual cell on game board
* Rectangle pos
* Color color
* bool isHover
* BP bp
* int figure - pawn, rook, etc.
* int team - whites of blacks
*/
typedef struct {
	Rectangle pos;
	Color color;
	bool isHover;
	BP bp;
	int figure;
	int team;
	int bitpos;
} VBC; // VisualBoardCell
//

/** 
 * @fucntion InitBoard
 * @brief initialize the visual board variable
 * **/
void InitBoard(int len, VBC board[len][len], int sWidth, int cSize);

/** 
 *@function PopulateBoard
 *@brief populates board with figures from bitmaps
 * **/
void PopulateBoard(int len, VBC board[len][len], BitboardMap *map);
void DrawCell(VBC *cell);
void DrawCellColor(VBC *cell, Color color);
void DrawFigure(VBC *cell, FT *ft, float scale);

#endif
