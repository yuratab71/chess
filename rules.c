#include "bitboard.h"
#include "rules.h"
#include "util.h"
#include <stdio.h>

Bitboard GetBPawnMoves(BitboardMap *map, int v, int h)
{
    Bitboard moves = 0;
    int pos = VHToBitmapPos(v, h);

    int target = pos - 8;
    if (target < 0 && target > 63)
    {
        return moves;
    };

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

Bitboard GetBKnightMoves(BitboardMap *map, int v, int h)
{
    int pos = VHToBitmapPos(v, h);
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

    printf("Knight moves");
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

    printf("\nVTOp : %d, VDown: %d\n", VTop, VDown);
    printf("v: %d, h: %d\n", v, h);
    int k1 = 1;
    for (int i = 0; i < VTop; i++)
    {
        printf("I = %d", i);
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
    //    int pos = VHToBitmapPos(v, h);

    printf("V: %d, H: %d\n", v, h);
    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    int RTop = (v < (8 - h) ? v : 8 - h);

    int LTop = (v < h ? v : h);

    int RDown = ((8 - v) < (8 - h)) ? (8 - v) : (8 - h);

    int LDown = (8 - v) < h ? (8 - v) : h;

    printf("RTop: %d, LTop: %d\n", RTop, LTop);
    printf("RDown: %d, LDown: %d\n", RDown, LDown);
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
