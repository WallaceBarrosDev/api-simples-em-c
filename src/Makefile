all:
	gcc -o program -lsqlite3 *.c interfaces/**/*.c interfaces/*.c services/*.c api/*.c -Wall -Wextra -pedantic -Werror -std=c11
	@clear
	./program

b:
	@clear
	gcc -o program main.c -Wall -Wextra -pedantic -Werror -std=c11
