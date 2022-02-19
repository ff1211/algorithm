CC=g++
CFLAGS=-I../seq 

mainmake: main.o math/math_alg.o
	$(CC) $(CFLAGS) -o main main.o math/math_alg.o