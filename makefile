ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif
all: main.o metaFunction.o
	$(CC) -o program main.o metaFunction.o

main.o: main.c metaFunction.c
	$(CC) -c main.c

metaFunction.o: metaFunction.c header.h
	$(CC) -c metaFunction.c
clean:
	rm *.o
	rm *~
run: all
	./program
