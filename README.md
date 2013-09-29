Text File Envryption/Decryption Utilities, C++
==============================================

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

Author:
=======
This software was developed and is maintained by Fadi Hanna Al-Kass (http://fadialkass.blogspot.com/).
