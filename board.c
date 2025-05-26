#include "board.h"
#include <raylib.h>

void InitBoard(int len, VBCR board[len][len], int sWidth, int cSize)
{
    for (int i = 0; i < len; i++) // vertical
    {
        for (int j = 0; j < len; j++) // horizontal
        {
            board[i][j].color = ((j + i + 1) % 2) ? BLACK : WHITE;
            board[i][j].pos.x = (float)(sWidth - 8 * cSize) + j * cSize;
            board[i][j].pos.y = (float)i * cSize;
            board[i][j].pos.width = cSize;
            board[i][j].pos.height = cSize;
            board[i][j].isHover = false;
        };
    };
    return;
};

void DrawCell(VBCR cell)
{
    DrawRectangleRec(cell.pos, cell.isHover ? GREEN : cell.color);
    return;
};
