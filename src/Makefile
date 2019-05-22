CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
EXEC=42sh

SS=./42sh
SRCDOT=$(wildcard dot/*.c)
SRC= $(wildcard parser/*.c)
SRCMAIN= $(wildcard *.c) 
SRCAST= $(wildcard ast/*.c)
SRCTEST= $(wildcard parser/test/*.c)
OBJDOT=$(SRCDOT:.c=.o)
OBJMAIN= $(SRCMAIN:.c=.o) 
OBJ= $(SRC:.c=.o)
OBJAST= $(SRCAST:.c=.o)
OBJTEST= $(SRCTEST:.c=.o)
42sh:$(OBJDOT) $(OBJ) $(OBJAST) $(OBJMAIN)
all:$(EXEC)
	$(CC) $(OBJDOT) $(OBJ) $(OBJAST) $(OBJMAIN) -o $(EXEC)
PHONY:clean
clean:
	$(RM) $(OBJ) $(OBJAST) $(OBJTEST) $(OBJDOT) $(OBJMAIN) $(EXEC)
