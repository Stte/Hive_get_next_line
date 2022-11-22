SRCS = ../get_next_line.c ../get_next_line_utils.c
BONUS = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
TESTS = test.c ./unity/unity.c
FLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=10000000
CC = gcc

all: run

run:
	$(CC) $(FLAGS) $(SRCS) main.c
	./a.out

test:
	$(CC) $(FLAGS) $(TESTS) $(SRCS) -o run_test
	./run_test

bonus:
	$(CC) $(FLAGS) $(BONUS) main.c
	./a.out

btest:
	$(CC) $(FLAGS) $(TESTS) $(BONUS) -o run_test
	./run_test
