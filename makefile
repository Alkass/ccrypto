CC = g++
CC_ARGS = -Wall -Werror -O3

build: keygen.cpp encryptor.cpp decryptor.cpp
  $(CC) ${CC_ARGS} -o keygen keygen.cpp
  $(CC) ${CC_ARGS} -o encryptor encryptor.cpp
  $(CC) ${CC_ARGS} -o decryptor decryptor.cpp
  
install:
  make build
  sudo mv keygen encryptor decryptor /bin/
