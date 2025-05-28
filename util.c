#include "figure.h"
#include "util.h"

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
