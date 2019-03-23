CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
EXEC=42sh

SS=./42sh
SRC= $(wildcard ./*.c)
SRCAST= $(wildcard ../ast/*.c)
OBJ= $(SRC:.c=.o)
OBJAST= $(SRCAST:.c=.o)
42sh: $(OBJ) $(OBJAST)

all:$(EXEC)
	$(CC) $(OBJ) -o $(OBJAST) $(EXEC)
	$(SS)
PHONY:clean
clean:
	$(RM) $(OBJ) $(OBJAST) $(EXEC)
