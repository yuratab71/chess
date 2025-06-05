#include "bitboard.h"
#include "board.h"
#include "figure.h"
#include "raylib.h"
#include "rules.h"
#include "textures.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>

#define WINDOW_WIDTH 1280;
#define WINDOW_HEIGHT 960;

BitboardMap bitmap;

Vector2 mousePos;
typedef struct
{
    BP bp;
    int figure;
    int team;
    int bitpos;
} FCell;

int main()
{
    int sWidth = WINDOW_WIDTH;
    int sHeight = WINDOW_HEIGHT;
    int cSize = CELL_SIZE;
    const int bSize = 8;
    bool shouldCalculate = false;

    Bitboard possibleMoves = 0;

    VBC board[bSize][bSize];
    FCell focusedCell;
    FCell selectedCell;

    FT ft;
    float ts = TEXTURE_SCALE; // texture scale
    focusedCell.bp.v = 0;
    focusedCell.bp.h = 0;

    int playerTeam = B;

    // Game objects Init
    InitBoard(bSize, board, sWidth, cSize);
    InitBlacks(&bitmap);
    InitWhites(&bitmap);

    PopulateBoard(bSize, board, &bitmap);

    // Raylib System Init
    InitWindow(sWidth, sHeight, "CHESS");
    SetWindowState(FLAG_VSYNC_HINT);

    // LoadGame Textures
    LoadGameTextures(&ft);

    while (!WindowShouldClose())
    {
        // Visual Board Representation
        // 1a must be black cell with BLACK rook
        mousePos = GetMousePosition();
        if (shouldCalculate && selectedCell.figure)
        {
            switch (selectedCell.figure)
            {
            case PAWN:
                possibleMoves = GetBPawnMoves(&bitmap, selectedCell.bp.v, selectedCell.bp.h);
                shouldCalculate = false;
                break;
            case KNIGHT:
                possibleMoves = GetBKnightMoves(&bitmap, selectedCell.bp.v, selectedCell.bp.h);
                shouldCalculate = false;
                break;
            case ROOK:
                possibleMoves = GetBRookMoves(&bitmap, selectedCell.bp.v, selectedCell.bp.h);
                shouldCalculate = false;
                break;
            case BISHOP:
                possibleMoves = GetBBishopMoves(&bitmap, selectedCell.bp.v, selectedCell.bp.h);
                shouldCalculate = false;
                break;
            case QUEEN:
                possibleMoves = GetBQueenMoves(&bitmap, selectedCell.bp.v, selectedCell.bp.h);
                shouldCalculate = false;
                break;
            default:
                break;
            }
        };

        BeginDrawing();
        ClearBackground(BLUE);

        int k = 0;
        for (int i = 0; i < bSize; i++) // vertical
        {
            for (int j = 0; j < bSize; j++) // horizontal
            {
                board[i][j].isHover = CheckCollisionPointRec(mousePos, board[i][j].pos);
                if (board[i][j].isHover)
                {
                    focusedCell.bp = board[i][j].bp;
                    focusedCell.figure = board[i][j].figure;
                    focusedCell.team = board[i][j].team;
                    focusedCell.bitpos = k;
                };
                DrawCell(&board[i][j]);
                DrawFigure(&board[i][j], &ft, ts);
                DrawText(TextFormat("%d", k), board[i][j].pos.x, board[i][j].pos.y, 45, RED);
                if (is_bit_set(possibleMoves, k))
                {
                    DrawCellColor(&board[i][j], RED);
                };
                k++;
            };
        };
        // End of VISUAL BOARD REPRESENTATION

        // Input section
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            if (focusedCell.figure && focusedCell.team == playerTeam)
            {
                shouldCalculate = true;
                selectedCell = focusedCell;
                possibleMoves = 0;
            };

            if (is_bit_set(possibleMoves, focusedCell.bitpos))
            {
                if (selectedCell.figure == PAWN || selectedCell.figure == KNIGHT || selectedCell.figure == ROOK ||
                    selectedCell.figure == BISHOP || selectedCell.figure == QUEEN)
                {
                    DispatchMove(selectedCell.figure, selectedCell.team, &bitmap, selectedCell.bitpos,
                                 focusedCell.bitpos);
                    PopulateBoard(bSize, board, &bitmap);
                    possibleMoves = 0;
                    selectedCell.figure = 0;
                    selectedCell.team = 0;
                    selectedCell.bitpos = 0;
                    selectedCell.bp.v = 0;
                    selectedCell.bp.h = 0;
                };
            };
        };

        // Draw System Info, debugging and visualization
        DrawText(TextFormat("%c%d", NumToCharCoordinate(focusedCell.bp.h), focusedCell.bp.v), 2, 15, 25, BLACK);
        DrawText(TextFormat("Focused: %c %c", NumToSideName(focusedCell.team), NumToFigureName(focusedCell.figure)), 2,
                 35, 25, BLACK);
        DrawText(TextFormat("Selected: %c %c", NumToSideName(selectedCell.team), NumToFigureName(selectedCell.figure)),
                 2, 55, 25, BLACK);
        DrawText(TextFormat("Bitpos - %d", focusedCell.bitpos), 2, 75, 25, BLACK);
        EndDrawing();
    };

    UnloadGameTextures(&ft);
    CloseWindow();
};
