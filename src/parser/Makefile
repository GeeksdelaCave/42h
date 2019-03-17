CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
EXEC=42sh

SS=./42sh
SRC= $(wildcard ./*.c)
OBJ= $(SRC:.c=.o)

42sh: $(OBJ)

all:$(EXEC)
	$(CC) $(OBJ) -o $(EXEC)
	$(SS)

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TEST_OBJ) $(EXEC)
