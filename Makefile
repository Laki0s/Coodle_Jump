CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lncurses

SRC = src/main.c src/game.c src/doodle.c src/platform.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = doodle_jump

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
