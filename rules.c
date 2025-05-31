#include "bitboard.h"
#include "rules.h"

Bitboard GetBPawnMoves(BitboardMap *map, int pos)
{
    Bitboard moves = 0;
    int target = pos - 8;
    if (!is_bit_set(map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing, target))
    {
        moves |= (1ULL << target);
    };

    if (pos >= 48 && pos < 56)
    {
        if (!is_bit_set(map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing,
                        target - 8))
        {
            moves |= (1ULL << (target - 8));
        }
    }

    return moves;
};
