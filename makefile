CC = g++
CC_ARGS = -Wall -Werror -O3

all: keygen encrypt decrypt

keygen: keygen.o
	$(CC) $(CC_ARGS) -o keygen keygen.o

encrypt: encryptor.o
	$(CC) $(CC_ARGS) -o encrypt encryptor.o

decrypt: decryptor.o
	$(CC) $(CC_ARGS) -o decrypt decryptor.o

install: all
	sudo cp keygen encrypt decrypt /usr/bin/
	
clean:
	rm -f *.o
