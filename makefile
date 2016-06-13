build:
  g++ -Wall -Werror -O3 -o keygen keygen.cpp
  g++ -Wall -Werror -O3 -o encryptor encryptor.cpp
  g++ -Wall -Werror -O3 -o decryptor decryptor.cpp
  
install:
  sudo g++ -Wall -Werror -O3 -o /bin/keygen keygen.cpp
  sudo g++ -Wall -Werror -O3 -o /bin/encryptor encryptor.cpp
  sudo g++ -Wall -Werror -O3 -o /bin/decryptor decryptor.cpp
