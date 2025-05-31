#ifndef RULES_H_
#define RULES_H_

#include "bitboard.h"
typedef struct {
	Bitboard init;
	Bitboard target;
} Move;

Bitboard GetBPawnMoves(BitboardMap *map, int pos);


#endif 
