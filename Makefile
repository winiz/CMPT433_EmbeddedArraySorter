all:
	gcc -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror sorter.c main.c -o sorter -pthread
clean:
	$(RM) sorter