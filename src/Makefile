CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
EXEC=42sh

SS=./42sh
SRCDOT=$(wildcard dot/*.c)
SRC= $(wildcard parser/*.c)
SRCAST= $(wildcard ast/*.c)
SRCTEST= $(wildcard parser/test/*.c)
OBJDOT=$(SRCDOT:.c=.o)
OBJ= $(SRC:.c=.o)
OBJAST= $(SRCAST:.c=.o)
OBJTEST= $(SRCTEST:.c=.o)
42sh:$(OBJDOT) $(OBJ) $(OBJAST) $(OBJTEST)
all:$(EXEC)
	$(CC) $(OBJDOT) $(OBJ) $(OBJAST) $(OBJTEST) -o $(EXEC)
	$(SS)
PHONY:clean
clean:
	$(RM) $(OBJ) $(OBJAST) $(OBJTEST) $(OBJDOt) $(EXEC)
