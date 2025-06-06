#include "bitboard.h"
#include "figure.h"
#include "rules.h"
#include "util.h"

Bitboard GetPawnMoves(BitboardMap *map, int v, int h, enum Team team)
{
    Bitboard moves = 0;
    Bitboard enemy, allies;
    int VTop, VTop2, VStart;

    int T = (team == BLACKS) ? -1 : 1;
    VStart = (team == BLACKS) ? 7 : 2;

    VTop = v + (1 * T);
    VTop2 = v + (2 * T);

    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    if (team == BLACKS)
    {
        allies = blacks;
        enemy = whites;
    };
    if (team == WHITES)
    {
        allies = whites;
        enemy = blacks;
    };

    // Move forward
    if (!is_bit_set(allies | enemy, VHToBitmapPos(VTop, h)))
    {
        set_bit(&moves, VHToBitmapPos(VTop, h));
    };

    // If pawn is on starting position it can move 2cells
    if (v == VStart)
    {
        if (!is_bit_set(enemy | allies, VHToBitmapPos(VTop, h)) && !is_bit_set(allies | enemy, VHToBitmapPos(VTop2, h)))
        {
            set_bit(&moves, VHToBitmapPos(VTop2, h));
        }
    }

    if ((h - 1) > 0 && is_bit_set(enemy, VHToBitmapPos(VTop, h - 1)))
    {
        set_bit(&moves, VHToBitmapPos(VTop, h - 1));
    };
    if ((8 - h) > 0 && is_bit_set(enemy, VHToBitmapPos(VTop, h + 1)))
    {
        set_bit(&moves, VHToBitmapPos(VTop, h + 1));
    };

    return moves;
};

Bitboard GetKnightMoves(BitboardMap *map, int v, int h, enum Team team)
{
    int pos = VHToBitmapPos(v, h);
    Bitboard moves = 0;
    Bitboard allies;
    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;

    allies = team == BLACKS ? blacks : whites;

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

            if (!is_bit_set(allies, targets[i]))
            {
                moves |= (1ULL << (targets[i]));
            };
        };
    };

    return moves;
};

Bitboard GetRookMoves(BitboardMap *map, int v, int h, enum Team team)
{
    Bitboard moves = 0;
    Bitboard allies, enemy;
    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;
    if (team == BLACKS)
    {
        allies = blacks;
        enemy = whites;
    };
    if (team == WHITES)
    {
        allies = whites;
        enemy = blacks;
    };

    int VTop = v - 1;
    int VDown = 8 - v;

    int HRight = 8 - h;
    int HLeft = h - 1;

    for (int i = 1; i < VTop + 1; i++)
    {
        if (is_bit_set(allies, VHToBitmapPos(v - i, h)))
        {
            break;
        }
        else
        {
            set_bit(&moves, VHToBitmapPos(v - i, h));
        };
        if (is_bit_set(enemy, VHToBitmapPos(v - i, h)))
            break;
    };

    for (int i = 1; i < VDown + 1; i++)
    {
        if (is_bit_set(allies, VHToBitmapPos(v + i, h)))
        {
            break;
        }
        else
        {
            set_bit(&moves, VHToBitmapPos(v + i, h));
        };

        if (is_bit_set(enemy, VHToBitmapPos(v + i, h)))
            break;
    };

    for (int i = 1; i < HRight + 1; i++)
    {
        if (is_bit_set(allies, VHToBitmapPos(v, h + i)))
        {
            break;
        }
        else
        {
            set_bit(&moves, VHToBitmapPos(v, h + i));
        };
        if (is_bit_set(enemy, VHToBitmapPos(v, h + i)))
            break;
    };

    for (int i = 1; i < HLeft + 1; i++)
    {
        if (is_bit_set(allies, VHToBitmapPos(v, h - i)))
        {
            break;
        }
        else
        {
            set_bit(&moves, VHToBitmapPos(v, h - i));
        };
        if (is_bit_set(enemy, VHToBitmapPos(v, h - i)))
            break;
    };

    // TODO add castling

    return moves;
};

Bitboard GetBishopMoves(BitboardMap *map, int v, int h, enum Team team)
{
    Bitboard moves = 0;
    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;
    Bitboard allies, enemy;
    if (team == BLACKS)
    {
        allies = blacks;
        enemy = whites;
    };
    if (team == WHITES)
    {
        allies = whites;
        enemy = blacks;
    };

    int RTop = (v < (8 - h) ? (v - 1) : 8 - h);

    int LTop = (v < h ? v - 1 : h - 1);

    int RDown = ((8 - v) < (8 - h)) ? (8 - v) : (8 - h);

    int LDown = (8 - v) < h ? (7 - v) : h - 1;

    for (int i = 1; i <= RTop; i++)
    {
        int target = VHToBitmapPos(v - 1 * i, h + 1 * i);
        if (is_bit_set(allies, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(enemy, target))
        {
            break;
        };
    };

    for (int i = 1; i <= LTop; i++)
    {
        int target = VHToBitmapPos(v - 1 * i, h - 1 * i);
        if (is_bit_set(allies, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(enemy, target))
        {
            break;
        };
    };
    for (int i = 1; i <= RDown; i++)
    {
        int target = VHToBitmapPos(v + 1 * i, h + 1 * i);
        if (is_bit_set(allies, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(enemy, target))
        {
            break;
        };
    };
    for (int i = 1; i <= LDown; i++)
    {
        int target = VHToBitmapPos(v + 1 * i, h - 1 * i);
        if (is_bit_set(allies, target))
        {
            break;
        };
        set_bit(&moves, target);
        if (is_bit_set(enemy, target))
        {
            break;
        };
    };

    return moves;
};

Bitboard GetQueenMoves(BitboardMap *map, int v, int h, enum Team team)
{
    Bitboard moves = 0;

    moves = GetBishopMoves(map, v, h, team) | GetRookMoves(map, v, h, team);

    return moves;
};

Bitboard GetKingMoves(BitboardMap *map, int v, int h, enum Team team)
{
    Bitboard moves = 0;
    Bitboard allies;
    Bitboard blacks = map->bPawns | map->bKnights | map->bRooks | map->bBishops | map->bQueen | map->bKing;
    Bitboard whites = map->wPawns | map->wKnights | map->wRooks | map->wBishops | map->wQueen | map->wKing;
    if (team == BLACKS)
    {
        allies = blacks;
    };
    if (team == WHITES)
    {
        allies = whites;
    };
    int VTop = v - 1;
    int VDown = 8 - v;

    int HRight = 8 - h;
    int HLeft = h - 1;

    if (VTop && !is_bit_set(allies, VHToBitmapPos(v - 1, h)))
    {
        set_bit(&moves, VHToBitmapPos(v - 1, h));
    };
    if (VDown && !is_bit_set(allies, VHToBitmapPos(v + 1, h)))
    {
        set_bit(&moves, VHToBitmapPos(v + 1, h));
    };
    if (HRight && !is_bit_set(allies, VHToBitmapPos(v, h + 1)))
    {
        set_bit(&moves, VHToBitmapPos(v, h + 1));
    };
    if (HLeft && !is_bit_set(allies, VHToBitmapPos(v, h - 1)))
    {
        set_bit(&moves, VHToBitmapPos(v, h - 1));
    };

    return moves;
};
