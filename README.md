Text File Envryption/Decryption Utilities
=========================================

Description:
============
This is a text file encryption/decryption program written in C++.


How does it Work?
=================
Basically, you create your own private key via the `keygen` utility. You, then, will execute the `encrypt` utility with two arguments; private key file path, and text file to be encrypted. The `decrypt` utility, however, will take the same arguments and return the original file content. Refer to the `How-to Use` section for help with execution & usage.


Note: This is a non-gui application, meaning that all operations are to be performed through a command line interface (e.g. Terminal)

Requirements:
=============
  1. Debian-based Linux distro, or any Mac OS X distro.
  2. g++ compiler built-in to the system.

How-to Compile:
==============
To compile all 3 tools, simply run the attached `compile.sh` script with root permissions (i.e. sudo ./compile.sh)

How-to Use:
===========
  - To generate a new private key, simply type in `keygen` into Terminal.
  - To save generated private key, use the output redirection feature supported in Linux/Mac OS X (i.e. '>') followed by desired private key file name (You're not obligated to have a file extension).
  
  `keygen > myPrivateKey.key` #this will save your private key into a new file named MyPrivateKey.key in present directory.
  
  - To encrypt a file, use the `encrypt` utility. 
           
            
Author:
=======
This software was developed and is maintained by Fadi Hanna Al-Kass (http://fadialkass.blogspot.com/).
