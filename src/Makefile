CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
EXEC=42sh

SS=./42sh
SRC= $(wildcard parser/*.c)
SRCAST= $(wildcard ast/*.c)
SRCTEST= $(wildcard parser/test/*.c)
OBJ= $(SRC:.c=.o)
OBJAST= $(SRCAST:.c=.o)
OBJTEST= $(SRCTEST:.c=.o)
42sh: $(OBJ) $(OBJAST) $(OBJTEST)

all:$(EXEC)
	$(CC) $(OBJ) $(OBJAST) $(OBJTEST) -o $(EXEC)
	$(SS)
PHONY:clean
clean:
	$(RM) $(OBJ) $(OBJAST) $(OBJTEST) $(EXEC)
