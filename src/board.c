#include "bitboard.h"
#include "board.h"
#include "figure.h"
#include "textures.h"
#include "util.h"
#include <iso646.h>
#include <raylib.h>
#include <stdio.h>

void InitBoard(int len, VBC board[len][len], int sWidth, int cSize)
{
    int k = 0;
    for (int i = 0; i < len; i++) // vertical
    {
        for (int j = 0; j < len; j++) // horizontal
        {
            int v = i + 1;
            int h = j + 1;

            board[i][j].color = ((j + i + 1) % 2) ? WHITE : BLACK;
            board[i][j].pos.x = (float)(sWidth - 8 * cSize) + j * cSize;
            board[i][j].pos.y = (float)i * cSize;
            board[i][j].pos.width = cSize;
            board[i][j].pos.height = cSize;
            board[i][j].isHover = false;
            board[i][j].bp.h = h;
            board[i][j].bp.v = v;
            board[i][j].team = 0;
            board[i][j].figure = 0;
            board[i][j].bitpos = k;
            k++;
        };
    };
    return;
};

void PopulateBoard(int len, VBC board[len][len], BitboardMap *map)
{
    PrintBitboard(&map->wPawns);
    int k = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            board[i][j].figure = 0;
            board[i][j].team = 0;

            if (is_bit_set(map->wPawns, k))
            {
                board[i][j].figure = PAWN;
                board[i][j].team = WHITES;
            };
            if (is_bit_set(map->bPawns, k))
            {
                board[i][j].figure = PAWN;
                board[i][j].team = BLACKS;
            };
            if (is_bit_set(map->wKnights, k))
            {
                board[i][j].figure = KNIGHT;
                board[i][j].team = WHITES;
            };
            if (is_bit_set(map->bKnights, k))
            {
                board[i][j].figure = KNIGHT;
                board[i][j].team = BLACKS;
            };
            if (is_bit_set(map->wRooks, k))
            {
                board[i][j].figure = ROOK;
                board[i][j].team = WHITES;
            };
            if (is_bit_set(map->bRooks, k))
            {
                board[i][j].figure = ROOK;
                board[i][j].team = BLACKS;
            };
            if (is_bit_set(map->wBishops, k))
            {
                board[i][j].figure = BISHOP;
                board[i][j].team = WHITES;
            };
            if (is_bit_set(map->bBishops, k))
            {
                board[i][j].figure = BISHOP;
                board[i][j].team = BLACKS;
            };
            if (is_bit_set(map->wQueen, k))
            {
                board[i][j].figure = QUEEN;
                board[i][j].team = WHITES;
            };
            if (is_bit_set(map->bQueen, k))
            {
                board[i][j].figure = QUEEN;
                board[i][j].team = BLACKS;
            };
            if (is_bit_set(map->wKing, k))
            {
                board[i][j].figure = KING;
                board[i][j].team = WHITES;
            };
            if (is_bit_set(map->bKing, k))
            {
                board[i][j].figure = KING;
                board[i][j].team = BLACKS;
            };

            k++;
        };
    }

    return;
};

void DrawCell(VBC *cell)
{
    DrawRectangleRec(cell->pos, cell->isHover ? GREEN : cell->color);

    return;
};

void DrawCellColor(VBC *cell, Color color)
{
    DrawRectangleRec((Rectangle){cell->pos.x + 25, cell->pos.y + 25, 80, 80}, color);

    return;
};

void DrawFigure(VBC *cell, FT *ft, float scale)
{
    Vector2 pos = {cell->pos.x + 25.0f, cell->pos.y - 20.0f};
    switch (cell->figure)
    {
    case PAWN:
        DrawTextureEx(cell->team == WHITES ? ft->wPawn : ft->bPawn, pos, 0.0f, scale, WHITE);
        return;
    case ROOK:
        DrawTextureEx(cell->team == WHITES ? ft->wRook : ft->bRook, pos, 0.0f, scale, WHITE);
        return;
    case BISHOP:
        DrawTextureEx(cell->team == WHITES ? ft->wBishop : ft->bBishop, pos, 0.0f, scale, WHITE);
        return;
    case KNIGHT:
        DrawTextureEx(cell->team == WHITES ? ft->wKnight : ft->bKnight, pos, 0.0f, scale, WHITE);
        return;
    case QUEEN:
        DrawTextureEx(cell->team == WHITES ? ft->wQueen : ft->bQueen, pos, 0.0f, scale, WHITE);
        return;
    case KING:
        DrawTextureEx(cell->team == WHITES ? ft->wKing : ft->bKing, pos, 0.0f, scale, WHITE);
        return;
    default:
        return;
    };
};
