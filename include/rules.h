#ifndef RULES_H_
#define RULES_H_

#include "bitboard.h"
typedef struct {
	Bitboard init;
	Bitboard target;
} Move;

Bitboard GetPawnMoves(BitboardMap *map, int v, int h, enum Team team);
Bitboard GetKnightMoves(BitboardMap *map, int v, int h, enum Team team);
Bitboard GetRookMoves(BitboardMap *map, int v, int h, enum Team team);
Bitboard GetBishopMoves(BitboardMap *map, int v, int h, enum Team team);
Bitboard GetQueenMoves(BitboardMap *map, int v, int h, enum Team team);
Bitboard GetKingMoves(BitboardMap *map, int v, int h, enum Team team);

#endif 
