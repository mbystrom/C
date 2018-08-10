CC=g++
FLAGS=-c -Wall -std=c++1y

all: maze

maze: main.o matrix.o maze.o
	$(CC) -o maze main.o matrix.o maze.o

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp

maze.o: maze.cpp
	$(CC) $(FLAGS) maze.cpp

clean:
	rm *.o maze
