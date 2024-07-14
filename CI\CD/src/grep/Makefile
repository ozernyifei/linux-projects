NAME = s21_grep
CC=gcc
SRC = s21_grep.c process.c utils.c
HEADERS = s21_grep.h
OBJS = $(patsubst %.c, %.o, $(SRC))
DIR_OBJS = objs
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))
CFLAGS=-Wall -Wextra -Werror -g -std=c11
clang_path= ../../materials/linters/

all: $(NAME)

s21_grep: $(PATH_OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o: %.c $(HEADERS) Makefile
	mkdir -p $(DIR_OBJS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJS) $(NAME)
	rm -rf .clang-format

check:
	cppcheck --enable=all --suppress=missingIncludeSystem ../grep
	valgrind --tool=memcheck --leak-check=yes -s ./s21_grep s21_grep.c 
	
format:
	cp $(clang_path).clang-format ./
	clang-format -n *.c *.h

clang_replace:
	cp $(clang_path).clang-format ./
	clang-format -i *.c *.h

rebuild: clean all