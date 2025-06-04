#ifndef RULES_H_
#define RULES_H_

#include "bitboard.h"
typedef struct {
	Bitboard init;
	Bitboard target;
} Move;

Bitboard GetBPawnMoves(BitboardMap *map, int v, int h);
Bitboard GetBKnightMoves(BitboardMap *map, int v, int h);
Bitboard GetBRookMoves(BitboardMap *map, int v, int h);
Bitboard GetBBishopMoves(BitboardMap *map, int v, int h);

#endif 
