#include "bitboard.h"
#include "rules.h"
#include "util.h"
#include <stdio.h>

Bitboard GetBPawnMoves(BitboardMap *map, int v, int h)
{
    Bitboard moves = 0;

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    // Move forward
    if (!is_bit_set(blacks | whites, VHToBitmapPos(v - 1, h)))
    {
        set_bit(&moves, VHToBitmapPos(v - 1, h));
    };

    // If pawn is on starting position it can move 2cells
    if (v == 7)
    {
        if (!is_bit_set(blacks | whites, VHToBitmapPos(v - 1, h)) &&
            !is_bit_set(blacks | whites, VHToBitmapPos(v - 2, h)))
        {
            set_bit(&moves, VHToBitmapPos(v - 2, h));
        }
    }

    if ((h - 1) > 0 && is_bit_set(whites, VHToBitmapPos(v - 1, h - 1)))
    {
        set_bit(&moves, VHToBitmapPos(v - 1, h - 1));
    };
    if ((8 - h) > 0 && is_bit_set(whites, VHToBitmapPos(v - 1, h + 1)))
    {
        set_bit(&moves, VHToBitmapPos(v - 1, h + 1));
    };

    return moves;
};

Bitboard GetBKnightMoves(BitboardMap *map, int v, int h)
{
    int pos = VHToBitmapPos(v, h);
    Bitboard moves = 0;

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

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
};

Bitboard GetBRookMoves(BitboardMap *map, int v, int h)
{
    Bitboard moves = 0;
    int pos = VHToBitmapPos(v, h);

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    int VTop = v;
    int VDown = 8 - v;

    int HRight = 8 - h;
    int HLeft = h;

    int k1 = 1;
    for (int i = 0; i < VTop; i++)
    {
        if (is_bit_set(blacks, pos - 8 * k1))
        {
            break;
        }
        else
        {
            set_bit(&moves, pos - 8 * k1);
            k1++;
        };
    };

    int k2 = 1;
    for (int i = 0; i < VDown; i++)
    {
        if (is_bit_set(blacks, pos + 8 * k2))
        {
            break;
        }
        else
        {
            set_bit(&moves, pos + 8 * k2);
            k2++;
        };
    };

    int k3 = 1;
    for (int i = 0; i < HRight; i++)
    {
        if (is_bit_set(blacks, pos + 1 * k3))
        {
            break;
        }
        else
        {
            set_bit(&moves, pos + 1 * k3);
            k3++;
        };
    };

    int k4 = 1;
    for (int i = 0; i < HLeft; i++)
    {
        if (is_bit_set(blacks, pos - 1 * k4))
        {
            break;
        }
        else
        {
            set_bit(&moves, pos - 1 * k4);
            k4++;
        }
    };

    // TODO add castling

    return moves;
};

Bitboard GetBBishopMoves(BitboardMap *map, int v, int h)
{
    Bitboard moves = 0;

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    int RTop = (v < (8 - h) ? v : 8 - h);

    int LTop = (v < h ? v : h);

    int RDown = ((8 - v) < (8 - h)) ? (8 - v) : (8 - h);

    int LDown = (8 - v) < h ? (8 - v) : h;

    for (int i = 1; i <= RTop; i++)
    {
        int target = VHToBitmapPos(v - 1 * i, h + 1 * i);
        printf("Target: %d\n", target);
        if (is_bit_set(blacks, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(whites, target))
        {
            break;
        };
    };

    for (int i = 1; i <= LTop; i++)
    {
        int target = VHToBitmapPos(v - 1 * i, h - 1 * i);
        if (is_bit_set(blacks, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(whites, target))
        {
            break;
        };
    };
    for (int i = 1; i <= RDown; i++)
    {
        int target = VHToBitmapPos(v + 1 * i, h + 1 * i);
        if (is_bit_set(blacks, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(whites, target))
        {
            break;
        };
    };
    for (int i = 1; i <= LDown; i++)
    {
        int target = VHToBitmapPos(v + 1 * i, h - 1 * i);
        if (is_bit_set(blacks, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(whites, target))
        {
            break;
        };
    };

    return moves;
};

Bitboard GetBQueenMoves(BitboardMap *map, int v, int h)
{
    Bitboard moves = 0;

    moves = GetBBishopMoves(map, v, h) | GetBRookMoves(map, v, h);

    return moves;
};

Bitboard GetBKingMoves(BitboardMap *map, int v, int h)
{
    Bitboard moves = 0;

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    int targets[4] = {VHToBitmapPos(v - 1, h), VHToBitmapPos(v + 1, h), VHToBitmapPos(v, h + 1),
                      VHToBitmapPos(v, h - 1)};

    for (int i = 0; i < 4; i++)
    {
        if (is_bit_set(blacks, targets[i]))
        {
            break;
        };
        set_bit(&moves, targets[i]);
    };

    return moves;
};
