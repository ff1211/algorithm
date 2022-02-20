CC= g++
CFLAGS=-std=c++11

mainmake: main.o math/math_alg.o
	$(CC) $(CFLAGS) -o main main.o math/math_alg.o