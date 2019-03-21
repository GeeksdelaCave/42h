CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g
#TEST_FLAG= -lcheck -lm -lpthread -lrt -lsubunit
EXEC=42sh
#TEST=mytest

# scr
SRC= $(wildcard ./*.c)
OBJ= $(SRC:.c=.o)

42sh: $(OBJ)

all:$(EXEC)
	$(CC) $(OBJ) -o $(EXEC)

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TEST_OBJ) $(EXEC)
