SRCS = ../get_next_line.c ../get_next_line_utils.c
TESTS = test.c ./unity/unity.c
FLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=42
CC = gcc

all: run

run:
	$(CC) $(FLAGS) $(SRCS) main.c
	./a.out

test:
	$(CC) $(FLAGS) $(TESTS) $(SRCS) -o run_test
	./run_test
