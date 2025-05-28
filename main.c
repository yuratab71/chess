#include "board.h"
#include "figure.h"
#include "raylib.h"
#include "textures.h"
#include "util.h"

#define WINDOW_WIDTH 1280;
#define WINDOW_HEIGHT 960;

Vector2 mousePos;
typedef struct
{
    BP bp;
    int figure;
} FCell;

int main()
{
    int sWidth = WINDOW_WIDTH;
    int sHeight = WINDOW_HEIGHT;
    int cSize = CELL_SIZE;
    const int bSize = 8;

    BC board[bSize][bSize];
    FCell focusedCell;
    FT ft;
    float ts = TEXTURE_SCALE; // texture scale
    focusedCell.bp.v = 0;
    focusedCell.bp.h = 0;

    int pSide = B;

    // Game objects Init
    InitBoard(bSize, board, sWidth, cSize);
    InitBoardFigures(bSize, board, pSide);

    // Raylib System Init
    InitWindow(sWidth, sHeight, "CHESS");
    SetWindowState(FLAG_VSYNC_HINT);

    // LoadGame Textures
    LoadGameTextures(&ft);

    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();

        BeginDrawing();
        ClearBackground(BLUE);

        for (int i = 0; i < bSize; i++) // vertical
        {
            for (int j = 0; j < bSize; j++) // horizontal
            {
                board[i][j].isHover = CheckCollisionPointRec(mousePos, board[i][j].pos);
                if (board[i][j].isHover)
                {
                    focusedCell.bp = board[i][j].bp;
                };
                DrawCell(&board[i][j]);
                DrawFigure(&board[i][j], &ft, ts);
            };
        };

        DrawText(TextFormat("%c%d", NumToCharCoordinate(focusedCell.bp.h), focusedCell.bp.v), 10, 70, 15, RAYWHITE);
        EndDrawing();
    };

    UnloadGameTextures(&ft);
    CloseWindow();
};
