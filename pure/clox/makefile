CC=gcc
filenames=chunk.c compiler.c debug.c main.c memory.c scanner.c value.c vm.c object.c
FLAGS=-c -Wall -std=c11

all: clox

clox: chunk.o compiler.o debug.o main.o memory.o object.o scanner.o value.o vm.o
	gcc -o clox chunk.o compiler.o debug.o main.o memory.o object.o scanner.o value.o vm.o

chunk.o: chunk.c
	gcc $(FLAGS) chunk.c

compiler.o: compiler.c
	gcc $(FLAGS) compiler.c

debug.o: debug.c
	gcc $(FLAGS) debug.c

main.o: main.c
	gcc $(FLAGS) main.c

memory.o: memory.c
	gcc $(FLAGS) memory.c

object.o: object.c
	gcc $(FLAGS) object.c

scanner.o: scanner.c
	gcc $(FLAGS) scanner.c

value.o: value.c
	gcc $(FLAGS) value.c

vm.o: vm.c
	gcc $(FLAGS) vm.c

clean:
	rm *.o clox

