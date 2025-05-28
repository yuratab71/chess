#include "raylib.h"
#include "textures.h"

void LoadGameTextures(FT *ft)
{
    ft->wPawn = LoadTexture("./assets/16x32 pieces/W_Pawn.png");
    ft->bPawn = LoadTexture("./assets/16x32 pieces/B_Pawn.png");

    ft->wRook = LoadTexture("./assets/16x32 pieces/W_Rook.png");
    ft->bRook = LoadTexture("./assets/16x32 pieces/B_Rook.png");

    ft->wBishop = LoadTexture("./assets/16x32 pieces/W_Bishop.png");
    ft->bBishop = LoadTexture("./assets/16x32 pieces/B_Bishop.png");

    ft->wKnight = LoadTexture("./assets/16x32 pieces/W_Knight.png");
    ft->bKnight = LoadTexture("./assets/16x32 pieces/B_Knight.png");

    ft->wQueen = LoadTexture("./assets/16x32 pieces/W_Queen.png");
    ft->bQueen = LoadTexture("./assets/16x32 pieces/B_Queen.png");

    ft->wKing = LoadTexture("./assets/16x32 pieces/W_King.png");
    ft->bKing = LoadTexture("./assets/16x32 pieces/B_King.png");
    return;
};

void UnloadGameTextures(FT *ft)
{
    UnloadTexture(ft->wPawn);
    UnloadTexture(ft->bPawn);
    UnloadTexture(ft->wRook);
    UnloadTexture(ft->bRook);
    UnloadTexture(ft->wBishop);
    UnloadTexture(ft->bBishop);
    UnloadTexture(ft->wKnight);
    UnloadTexture(ft->bKnight);
    UnloadTexture(ft->wQueen);
    UnloadTexture(ft->bQueen);
    UnloadTexture(ft->wKing);
    UnloadTexture(ft->bKing);
    return;
}
