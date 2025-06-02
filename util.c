#include "figure.h"
#include "util.h"
#include <stdio.h>

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

char NumToFigureName(int num)
{
    switch (num)
    {
    case PAWN:
        return 'P';
    case ROOK:
        return 'R';
    case BISHOP:
        return 'B';
    case KNIGHT:
        return 'H';
    case QUEEN:
        return 'Q';
    case KING:
        return 'K';
    default:
        return '0';
    };
};

char NumToSideName(int num)
{
    switch (num)
    {
    case W:
        return 'W';
    case B:
        return 'B';

    default:
        return '0';
    }
}

int VHToBitmapPos(int v, int h)
{
    return (v - 1) * 8 + (h - 1);
};

void PrintBitboard(Bitboard *bitboard)
{
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d", is_bit_set(*bitboard, k));
        };
        printf("\n");
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
    printf("Vt: %d, Vpos^ %d\n", vTarget, vPos);
    int result = vTarget - vPos;
    return ((unsigned)((result < 0) ? -result : result)) <= (unsigned)motionRange ? target : -1;
};
