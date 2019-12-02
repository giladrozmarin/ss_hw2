CC=gcc
OBJECTS_MAIN=myBank.o main.o
FLAGS= -Wall -g 

all : compile run clean

compile:
	$(CC) $(FLAGS) -o main.o main.c myBank.c
run:
	./main.o
myBank.o:
	$(CC) $(FLAGS) -o myBank.o myBank.c
clean:
	rm -f *.o mains