CC = gcc

CFLAGS = -Iinclude \
	 -std=c99 \
	 -Wall \
	 -Wextra \
	 -Wall \
	 -Werror

WIN_FLAGS = -lopengl32 \
	    -lgdi32 \
	    -lwinmm \
	    -Lraylib/win/lib \
	    -Iraylib/win/include \
	    -lraylib

LINUX_LFLAGS = -Lraylib/linux_amd64/lib \
	      -lraylib \
	      -lGL \
	      -lm \
	      -lpthread \
	      -ldl \
	      -lrt \
	      -lX11 \
	      -rpath='$ORIGIN/raylib/linux_amd64/lib'

LINUX_IFLAGS = -Iraylib/linux_amd64/include 
	 


SRC = $(wildcard src/*.c)
	
linux: src/main.c
	$(CC) -O2 $(SRC) -o Chess $(CFLAGS) $(LINUX_IFLAGS) $(LINUX_LFLAGS)

win: main.c
	gcc main.c board.c util.c textures.c bitboard.c rules.c -o Chess  -Wextra -Wall -std=c99 -Iraylib/win/include -Lraylib/win/lib -lraylib -lopengl32 -lgdi32 -lwinmm
