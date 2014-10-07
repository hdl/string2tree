main: clean queue.o
	gcc -g -o main queue.o main.c
queue.o:
		gcc -g -c queue.c -o queue.o
run:
		./main
clean:
		rm -rf main *.o
