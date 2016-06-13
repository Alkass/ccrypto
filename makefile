CC = g++
CC_ARGS = -Wall -Werror -O3

build: keygen.cpp encryptor.cpp decryptor.cpp
	$(CC) ${CC_ARGS} -o keygen keygen.cpp
	$(CC) ${CC_ARGS} -o encrypt encryptor.cpp
	$(CC) ${CC_ARGS} -o decrypt decryptor.cpp

install:
	make build
	sudo mv keygen encrypt decrypt /bin/
