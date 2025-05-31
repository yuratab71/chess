#ifndef UTIL_H_
#define UTIL_H_

#include "bitboard.h"
char NumToCharCoordinate(int num);
char NumToFigureName(int num);
char NumToSideName(int num);
int VHToBitmapPos(int v, int h);
void PrintBitboard(Bitboard *bitboard);

#endif
