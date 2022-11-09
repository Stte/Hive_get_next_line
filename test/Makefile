SRCS = ../get_next_line.c ../get_next_line_utils.c
TESTS = test.c ./unity/unity.c
FLAGS = -g
CC = gcc

all: test

test:
	$(CC) $(FLAGS) $(TESTS) $(SRCS) -o run_test
	./run_test
