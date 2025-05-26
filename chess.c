#include "board.h"
#include "raylib.h"

#define WINDOW_WIDTH 1280;
#define WINDOW_HEIGHT 960;

Vector2 mousePos;

int main()
{
    int sWidth = WINDOW_WIDTH;
    int sHeight = WINDOW_HEIGHT;
    int cSize = CELL_SIZE;
    const int bSize = 8;

    VBRC board[bSize][bSize];

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
        DrawText("Chess", 50, 50, 25, RAYWHITE);
        DrawText(TextFormat("Mouse x = %f, y = %f", mousePos.x, mousePos.y), 10, 70, 15, RAYWHITE);
        DrawBoard(8, board, mousePos);
        EndDrawing();
    };

    CloseWindow();
};
