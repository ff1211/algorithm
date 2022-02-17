CC=g++
CFLAGS=-I../seq

mainmake: main.o ./seq/rand_perm.o
	$(CC) $(CFLAGS) -o main main.o ./seq/rand_perm.o