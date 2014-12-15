File Encryptor/Decryptor
=========================================

Description
============
<h1> This is a text file encryption/decryption program written in C++. </h1>


How does it Work?
=================
Basically, you create your own private key via the `keygen` utility. You, then, will execute the `encrypt` utility with two arguments; private key file path, and text file to be encrypted. The `decrypt` utility, however, will take the same arguments and return the original file content. Refer to the `How-to Use` section for help with execution & usage.


Requirements
=============
  1. Debian-based Linux distro, or any Mac OS X distro.
  2. g++ compiler built-in to the system.


Build
==============
To `build` all 3 tools, simply run the attached `compile.sh` script with root permissions (i.e. `sudo ./build`)


Usage
===========
  - To generate a new private key, simply type in `keygen` into Terminal.
  - To save generated private key, use the output redirection feature supported in Linux/Mac OS X (i.e. '>') followed by desired private key file name (You're not obligated to have a file extension).
  
  `keygen > myPrivateKey.key` #this will save your private key into a new file named MyPrivateKey.key in present directory.
  
  - To encrypt a file, use the `encrypt` utility. Just like the case with `keygen`, you'll be using output redirection to store encrypted data into a file. However, `encrypt` utility, as stated above, takes two arguments, the first one being private key file name (which you may have generated already from the previous step) and a text file path.
  
  `encrypt myPrivateKey.key data.txt > myEncryptedData.dat` #this will use myPrivateKey.key to encrypt the content of an existing file called `data.txt` and redirect the output to a file named myEncryptedData.dat in present directory.    
  
  - To decrypt a file back into its original content, use the `decrypt` utility. Just like the case with `keygen` and `encrypt`, `decrypt` does NOT have a built-in output feature, so you'll need to use output redirection to store decrypted content into a file again. However, `decrypt`, similarly, takes private key file path as a first argument and an encrypted file path as a second argument.

  `decrypt myPrivateKey.key encryptedData.dat > myDecryptedData.txt` #this will use myPrivateKey.key to decrypt the content of an existing file called `encryptedData.dat` and redirect the output to a file named myDecryptedData.dat in present directory.    

 
Note(s)
========
1. This software is a non-GUI application, meaning that all operations are to be performed within the command-line environment (e.g. Terminal)
2. None of the three utilities perform any error-checking/-handeling, So if you were to give the program wrong input, do NOT expect an error message explaining what went wrong. 


Author
=======
This software was written and is currently only maintained by Fadi Hanna Al-Kass (http://fadialkass.blogspot.com/).
