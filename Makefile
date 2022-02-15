CC=clang
CFLAGS=-I ./seq -I ./tool

mainmake: main.o ./seq/rand_perm.o
	$(CC) $(CFLAGS) -o main main.o rand_perm.o