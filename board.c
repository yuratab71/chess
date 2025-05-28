#include "board.h"
#include "figure.h"
#include "textures.h"
#include <raylib.h>
#include <stdio.h>

void InitBoard(int len, BC board[len][len], int sWidth, int cSize)
{
    for (int i = 0; i < len; i++) // vertical
    {
        for (int j = 0; j < len; j++) // horizontal
        {
            int v = i + 1;
            int h = j + 1;

            board[i][j].color = ((j + i + 1) % 2) ? BLACK : WHITE;
            board[i][j].pos.x = (float)(sWidth - 8 * cSize) + j * cSize;
            board[i][j].pos.y = (float)i * cSize;
            board[i][j].pos.width = cSize;
            board[i][j].pos.height = cSize;
            board[i][j].isHover = false;
            board[i][j].bp.h = h;
            board[i][j].bp.v = v;
            board[i][j].side = 0;
            board[i][j].figure = 0;
        };
    };
    return;
};

void InitBoardFigures(int len, BC board[len][len], int pSide)
{
    for (int i = 0; i < len; i++)
    {
        printf("i = %d\n", i);
        board[1][i].figure = PAWN;
        board[1][i].side = (pSide == W ? B : W);

        board[6][i].figure = PAWN;
        board[6][i].side = pSide;
    };

    board[0][0].figure = ROOK;
    board[0][0].side = (pSide == W ? B : W);
    board[0][7].figure = ROOK;
    board[0][7].side = (pSide == W ? B : W);

    board[7][0].figure = ROOK;
    board[7][0].side = pSide;
    board[7][7].figure = ROOK;
    board[7][7].side = pSide;

    board[0][2].figure = BISHOP;
    board[0][2].side = pSide == W ? B : W;
    board[0][5].figure = BISHOP;
    board[0][5].side = pSide == W ? B : W;

    board[7][2].figure = BISHOP;
    board[7][2].side = pSide;
    board[7][5].figure = BISHOP;
    board[7][5].side = pSide;

    board[0][1].figure = KNIGHT;
    board[0][1].side = (pSide == W ? B : W);
    board[0][6].figure = KNIGHT;
    board[0][6].side = (pSide == W ? B : W);

    board[7][1].figure = KNIGHT;
    board[7][1].side = pSide;
    board[7][6].figure = KNIGHT;
    board[7][6].side = pSide;

    board[0][4].figure = QUEEN;
    board[0][4].side = (pSide == W ? B : W);
    board[0][3].figure = KING;
    board[0][3].side = (pSide == W ? B : W);

    board[7][3].figure = QUEEN;
    board[7][3].side = pSide;
    board[7][4].figure = KING;
    board[7][4].side = pSide;
    return;
};

void DrawCell(BC *cell)
{
    DrawRectangleRec(cell->pos, cell->isHover ? GREEN : cell->color);

    return;
};

void DrawFigure(BC *cell, FT *ft, float scale)
{
    Vector2 pos = {cell->pos.x + 25.0f, cell->pos.y - 20.0f};
    switch (cell->figure)
    {
    case PAWN:
        DrawTextureEx(cell->side == W ? ft->wPawn : ft->bPawn, pos, 0.0f, scale, WHITE);
        return;
    case ROOK:
        DrawTextureEx(cell->side == W ? ft->wRook : ft->bRook, pos, 0.0f, scale, WHITE);
        return;
    case BISHOP:
        DrawTextureEx(cell->side == W ? ft->wBishop : ft->bBishop, pos, 0.0f, scale, WHITE);
        return;
    case KNIGHT:
        DrawTextureEx(cell->side == W ? ft->wKnight : ft->bKnight, pos, 0.0f, scale, WHITE);
        return;
    case QUEEN:
        DrawTextureEx(cell->side == W ? ft->wQueen : ft->bQueen, pos, 0.0f, scale, WHITE);
        return;
    case KING:
        DrawTextureEx(cell->side == W ? ft->wKing : ft->bKing, pos, 0.0f, scale, WHITE);
        return;
    default:
        return;
    };
};
