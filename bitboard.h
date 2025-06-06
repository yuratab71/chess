#ifndef BITBOARD_H_
#define BITBOARD_H_

#include "figure.h"
#include <stdbool.h>
#include <stdint.h>

typedef uint64_t Bitboard;

typedef struct {
	Bitboard wPawns;
	Bitboard bPawns;
	Bitboard wRooks;
	Bitboard bRooks;
	Bitboard wBishops;
	Bitboard bBishops;
	Bitboard wKnights;
	Bitboard bKnights;
	Bitboard wQueen;
	Bitboard bQueen;
	Bitboard wKing;
	Bitboard bKing;
} BitboardMap;

void set_bit(Bitboard *bb, int bit);
void clear_bit(Bitboard *bb, int bit);
bool is_bit_set(Bitboard bb, int bit);

void InitWhites(BitboardMap *map);

void InitBlacks(BitboardMap *map);
void DispatchMove(enum FigureType figure, enum Team team, BitboardMap *map, int origin, int target);
void EatEnemyFigure(BitboardMap *map, int target, enum Team team);

#endif

