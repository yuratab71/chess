Chess: chess.c
	gcc chess.c board.c -o Chess  -Wextra -Wall -std=c99 -Iraylib/include -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
