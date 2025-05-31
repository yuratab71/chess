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
    case B:
        switch (figure)
        {
        case PAWN:
            set_bit(&map->bPawns, target);
            clear_bit(&map->bPawns, origin);
        default:
            break;
        };
        break;
    case W:
        break;
    default:
        break;
    };
};
