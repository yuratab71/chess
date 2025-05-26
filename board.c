#include "board.h"
#include <raylib.h>

void InitBoard(int len, VBRC board[len][len], int sWidth, int cSize)
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

void DrawBoard(int len, VBRC board[len][len], Vector2 mPos)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            board[i][j].isHover = CheckCollisionPointRec(mPos, board[i][j].pos);
            DrawRectangleRec(board[i][j].pos, board[i][j].isHover ? GREEN : board[i][j].color);
        };
    }

    return;
};
