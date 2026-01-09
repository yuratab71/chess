#ifndef TEXTURES_H_
#define TEXTURES_H_

#include "raylib.h"

#define TEXTURE_SCALE 4.0f;

typedef struct {
	Texture2D wPawn;
	Texture2D bPawn;
	Texture2D wRook;
	Texture2D bRook;
	Texture2D wBishop;
	Texture2D bBishop;
	Texture2D wKnight;
	Texture2D bKnight;
	Texture2D wQueen;
	Texture2D bQueen;
	Texture2D wKing;
	Texture2D bKing;
} FT;

void LoadGameTextures(FT *ft);
void UnloadGameTextures(FT *ft);

#endif
