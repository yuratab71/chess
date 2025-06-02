#include "bitboard.h"
#include "rules.h"
#include "util.h"
#include <stdio.h>

Bitboard GetBPawnMoves(BitboardMap *map, int pos)
{
    Bitboard moves = 0;
    int target = pos - 8;

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    // Move forward
    if (!is_bit_set(blacks | whites, target))
    {
        moves |= (1ULL << target);
    };

    // If pawn is on starting position it can move 2cells
    if (pos >= 48 && pos < 56)
    {
        if (!is_bit_set(blacks | whites, target - 8))
        {
            moves |= (1ULL << (target - 8));
        }
    }

    if (is_bit_set(whites, pos - 8 - 1))
    {
        moves |= (1ULL << (pos - 8 - 1));
    };

    if (is_bit_set(blacks, pos - 8 + 1))
    {
        moves |= (1ULL << (pos - 8 + 1));
    };

    return moves;
};

Bitboard GetBKnightMoves(BitboardMap *map, int pos)
{
    Bitboard moves = 0;

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    //    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    int targets[8] = {
        pos + 8 - 2,  pos + 8 + 2,

        pos + 16 + 1, pos + 16 - 1,

        pos - 8 - 2,  pos - 8 + 2,

        pos - 16 + 1, pos - 16 - 1,
    };
    for (int i = 0; i < 8; i++)
    {
        targets[i] = CheckOutOfBoard(pos, targets[i], 2);
        if (targets[i] >= 0 && targets[i] <= 63)
        {

            if (!is_bit_set(blacks, targets[i]))
            {
                moves |= (1ULL << (targets[i]));
            };
        };
    };

    return moves;
}
