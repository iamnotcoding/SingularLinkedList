CC=gcc

all:
	$(CC) LinkedList.c LBubbleSort.c main.c -std=c11 -g3 -Wall -Wextra -pedantic-errors -o main 
clean:
	rm main
