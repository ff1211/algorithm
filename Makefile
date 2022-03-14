CC		=	clang++
CFLAGS	=	-std=c++11

main:
	$(CC) $(CFLAGS) main.cpp seq/seq_alg.cpp -o main

clean:
	rm main