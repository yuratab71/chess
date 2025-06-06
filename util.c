#include "figure.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

char NumToCharCoordinate(int num)
{
    switch (num)
    {
    case 1:
        return 'a';
    case 2:
        return 'b';
    case 3:
        return 'c';
    case 4:
        return 'd';
    case 5:
        return 'e';
    case 6:
        return 'f';
    case 7:
        return 'g';
    case 8:
        return 'h';
    default:
        return '0';
    };
};

char *NumToFigureName(int num)
{
    switch (num)
    {
    case PAWN:
        return "Pawn";
    case ROOK:
        return "Rook";
    case BISHOP:
        return "Bishop";
    case KNIGHT:
        return "Knight";
    case QUEEN:
        return "Queen";
    case KING:
        return "King";
    default:
        return "None";
    };
};

char *NumToSideName(int num)
{
    switch (num)
    {
    case W:
        return "White";
    case B:
        return "Black";
    default:
        return "None";
    }
}

int VHToBitmapPos(int v, int h)
{
    return (v - 1) * 8 + (h - 1);
};

void PrintBitboard(Bitboard *bitboard)
{
    for (int i = 0; i < 64; i++)
    {
        printf("%d", is_bit_set(*bitboard, i) ? 1 : 0);
        if ((i + 1) % 8 == 0)
        {
            printf("\n");
        }
    };
    return;
};

int CheckOutOfBoard(int pos, int target, int motionRange)
{
    int vPos = pos;
    int vTarget = target;
    for (int i = 0; i < 8; i++)
    {
        if (!(vPos >= 0 && vPos <= 7))
        {
            vPos -= 8;
        };
        if (!(vTarget >= 0 && vTarget <= 7))
        {
            vTarget -= 8;
        }
    };
    return abs(vTarget - vPos) <= motionRange ? target : -1;
};
