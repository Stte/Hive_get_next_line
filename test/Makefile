SRCS = ../get_next_line.c ../get_next_line_utils.c
BONUS = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
TESTS = test.c ./unity/unity.c
FLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address
LIBSAN = -static-libsan
CC = gcc

all: run

run:
	$(CC) $(FLAGS) $(SRCS) main.c
	./a.out

test:
	$(CC) $(FLAGS) $(SANITIZE) $(LIBSAN) $(TESTS) $(SRCS) -o run_test
	./run_test

test_linux:
	$(CC) $(FLAGS) $(SANITIZE) $(TESTS) $(SRCS) -o run_test
	./run_test

bonus:
	$(CC) $(FLAGS) $(BONUS) main.c
	./a.out

btest:
	$(CC) $(FLAGS) $(SANITIZE) $(LIBSAN) $(TESTS) $(BONUS) -o run_test
	./run_test

btest_linux:
	$(CC) $(FLAGS) $(SANITIZE) $(TESTS) $(BONUS) -o run_test
	./run_test
