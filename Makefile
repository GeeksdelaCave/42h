CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
EXEC=42sh

SS=./42sh
SRC= $(wildcard src/parser/*.c)
SRCTEST= $(wildcard src/parser/test/*.c)
OBJ= $(SRC:.c=.o)
OBJTEST= $(SRCTEST:.c=.o)
42sh: $(OBJ) $(OBJTEST)
OBJTEST= $(SRCTEST:.c=.o)
42sh: $(OBJ) $(OBJTEST)

all:$(EXEC)
	$(CC) $(OBJ) $(OBJTEST) $(EXEC)
	$(CC) $(OBJ) $(OBJTEST) $(EXEC)
	$(SS)
PHONY:clean
clean:
	$(RM) $(OBJ) $(OBJTEST) $(EXEC)
	$(RM) $(OBJ) $(OBJTEST) $(EXEC)
