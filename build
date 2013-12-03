#!/bin/bash

if [ `id -u` -ne 0 ]
then
	echo "Root permissions are required for this script to execute"
	exit
fi

ENC_INPUT_FILE_NAME="encr*.cpp"
DEC_INPUT_FILE_NAME="decr*.cpp"
KEYG_INPUT_FILE_NAME="keyg*.cpp"
OUTPUT_PATH="/bin/"
ENC_OUTPUT_FILE_NAME="encrypt"
DEC_OUTPUT_FILE_NAME="decrypt"
KEYG_OUTPUT_FILE_NAME="keygen"


g++ -O3 $ENC_INPUT_FILE_NAME -o $OUTPUT_PATH$ENC_OUTPUT_FILE_NAME
g++ -O3 $DEC_INPUT_FILE_NAME -o $OUTPUT_PATH$DEC_OUTPUT_FILE_NAME
g++ -O3 $KEYG_INPUT_FILE_NAME -o $OUTPUT_PATH$KEYG_OUTPUT_FILE_NAME
