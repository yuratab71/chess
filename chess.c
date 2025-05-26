#include "board.h"
#include "raylib.h"
#include "util.h"

#define WINDOW_WIDTH 1280;
#define WINDOW_HEIGHT 960;

Vector2 mousePos;
typedef struct
{
    int v;
    int h;
    int figure;
} FCell;

int main()
{
    int sWidth = WINDOW_WIDTH;
    int sHeight = WINDOW_HEIGHT;
    int cSize = CELL_SIZE;
    const int bSize = 8;

    VBCR board[bSize][bSize];
    FCell focusedCell;

    focusedCell.h = 0;
    focusedCell.v = 0;

    // Game objects Init
    InitBoard(bSize, board, sWidth, cSize);

    // Raylib System Init
    InitWindow(sWidth, sHeight, "CHESS");
    SetWindowState(FLAG_VSYNC_HINT);

    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();

        BeginDrawing();
        ClearBackground(BLUE);

        for (int i = 0; i < bSize; i++)
        {
            for (int j = 0; j < bSize; j++)
            {
                board[i][j].isHover = CheckCollisionPointRec(mousePos, board[i][j].pos);
                if (board[i][j].isHover)
                {
                    focusedCell.v = i + 1;
                    focusedCell.h = j + 1;
                };
                DrawCell(board[i][j]);
            };
        };

        DrawText(TextFormat("%c%d", NumToCharCoordinate(focusedCell.h), focusedCell.v), 10, 70, 15, RAYWHITE);
        EndDrawing();
    };

    CloseWindow();
};
