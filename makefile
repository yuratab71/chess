Chess: main.c
	gcc main.c board.c util.c textures.c bitboard.c rules.c -o Chess  -Wextra -Wall -std=c99 -Iraylib/include -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
