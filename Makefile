CC=gcc

all:
	$(CC) LinkedList.c main.c -g -o main 
clean:
	rm main
