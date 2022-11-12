CC=g++

all: main

main: main.cpp radix.o
	$(CC) main.cpp radix.o -o main

radix: radix.cpp radix.hpp
	$(CC) radix.cpp radix.hpp -o radix.o