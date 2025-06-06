#include "bitboard.h"
#include "figure.h"
#include <stdbool.h>

void set_bit(Bitboard *bb, int bit)
{
    *bb |= (1ULL << bit);
};

void clear_bit(Bitboard *bb, int bit)
{
    *bb &= ~(1ULL << bit);
}

// Check if a bit is set at a given square
bool is_bit_set(Bitboard bb, int bit)
{
    return (bb & (1ULL << bit)) != 0;
}

void InitWhites(BitboardMap *map)
{
    // Pawns
    for (int i = 8; i < 16; i++)
    {
        set_bit(&map->wPawns, i);
    };

    set_bit(&map->wRooks, 0);
    set_bit(&map->wRooks, 7);

    set_bit(&map->wBishops, 2);
    set_bit(&map->wBishops, 5);

    set_bit(&map->wKnights, 1);
    set_bit(&map->wKnights, 6);

    set_bit(&map->wQueen, 4);
    set_bit(&map->wKing, 3);

    return;
};

void InitBlacks(BitboardMap *map)
{
    for (int i = 48; i < 56; i++)
    {
        set_bit(&map->bPawns, i);
    };

    set_bit(&map->bRooks, 63);
    set_bit(&map->bRooks, 56);

    set_bit(&map->bBishops, 61);
    set_bit(&map->bBishops, 58);

    set_bit(&map->bKnights, 62);
    set_bit(&map->bKnights, 57);

    set_bit(&map->bQueen, 60);
    set_bit(&map->bKing, 59);

    return;
};

void DispatchMove(enum FigureType figure, enum Team team, BitboardMap *map, int origin, int target)
{
    switch (team)
    {
    case BLACKS:
        switch (figure)
        {
        case PAWN:
            set_bit(&map->bPawns, target);
            clear_bit(&map->bPawns, origin);
            break;
        case KNIGHT:
            set_bit(&map->bKnights, target);
            clear_bit(&map->bKnights, origin);
            break;
        case ROOK:
            set_bit(&map->bRooks, target);
            clear_bit(&map->bRooks, origin);
            break;
        case BISHOP:
            set_bit(&map->bBishops, target);
            clear_bit(&map->bBishops, origin);
            break;
        case QUEEN:
            set_bit(&map->bQueen, target);
            clear_bit(&map->bQueen, origin);
            break;
        case KING:
            set_bit(&map->bKing, target);
            clear_bit(&map->bKing, origin);
            break;
        default:
            break;
        };
        break;
    case WHITES:
        switch (figure)
        {
        case PAWN:
            set_bit(&map->wPawns, target);
            clear_bit(&map->wPawns, origin);
            break;
        case KNIGHT:
            set_bit(&map->wKnights, target);
            clear_bit(&map->wKnights, origin);
            break;
        case ROOK:
            set_bit(&map->wRooks, target);
            clear_bit(&map->wRooks, origin);
            break;
        case BISHOP:
            set_bit(&map->wBishops, target);
            clear_bit(&map->wBishops, origin);
            break;
        case QUEEN:
            set_bit(&map->wQueen, target);
            clear_bit(&map->wQueen, origin);
            break;
        case KING:
            set_bit(&map->wKing, target);
            clear_bit(&map->wKing, origin);
            break;
        default:
            break;
        };
        break;
    default:
        break;
    };
};

void EatEnemyFigure(BitboardMap *map, int target, enum Team team)
{
    if (team == BLACKS)
    {
        clear_bit(&map->wPawns, target);
        clear_bit(&map->wRooks, target);
        clear_bit(&map->wKnights, target);
        clear_bit(&map->wBishops, target);
        clear_bit(&map->wQueen, target);
        clear_bit(&map->wKing, target);
    }
    else
    {
        clear_bit(&map->bPawns, target);
        clear_bit(&map->bRooks, target);
        clear_bit(&map->bKnights, target);
        clear_bit(&map->bBishops, target);
        clear_bit(&map->bQueen, target);
        clear_bit(&map->bKing, target);
    }
};
