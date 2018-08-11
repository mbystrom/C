CC=g++
FLAGS=-c -Wall -std=c++1y
PROGRAM_NAME=main

FILES=hello.cpp main.cpp math.cpp matrix.cpp
OBJECTS=$(FILES: .cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): hello.o main.o math.o matrix.o
	$(CC) -o $(PROGRAM_NAME) hello.o main.o math.o matrix.o

hello.o: hello.cpp
	$(CC) $(FLAGS) hello.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

math.o: math.cpp
	$(CC) $(FLAGS) math.cpp

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp

clean:
	rm *.o main

run:
	make
	./$(PROGRAM_NAME)
