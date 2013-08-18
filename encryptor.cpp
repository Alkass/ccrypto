/*
* Author: Fadi Al-Kass
* Project: Text Encryptor
*/


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>


using namespace std;

struct key
{
    static const unsigned int length = 96;

    char keyList[length];

    char operator[](unsigned int at)
    {
        return keyList[at];
    }

    void loadKey(const char * fileName)
    {
        ifstream inputFile(fileName);

        if (inputFile.is_open())
        {
            for (unsigned int i = 0; i < 96; i++)
            {
                string tmpLine;
                getline(inputFile, tmpLine);
                keyList[i] = tmpLine[i];
            }
        }
    }
};


struct file
{
    void loadFile(char * fileName)
    {
        ifstream inputFile(fileName);

        if (inputFile.is_open())
        {
            string line;
            while (getline(inputFile, line))
            {
                fileList.push_back(line);
            }
        }
    }

    string operator[](unsigned int at)
    {
        return fileList[at];
    }

    unsigned int length()
    {
        return fileList.size();
    }

private:
        vector<string> fileList;
};


void usage();
void encryptContent(file &, key &, vector<string> &);
char encryptChar(char, key &);
void outputToDisplay(vector<string> &);

int main(int argc, char * args[])
{
    if (argc < 3)
        usage();

    key someKey;
    someKey.loadKey(args[1]);

    file someFile;
    someFile.loadFile(args[2]);

    vector<string> encryptedContent;
    encryptContent(someFile, someKey, encryptedContent);

    outputToDisplay(encryptedContent);
}

void usage()
{
    cout << "Usage: encryptor [key-file] [file-name]" << endl;
    exit(EXIT_FAILURE);
}


void encryptContent(file & someFile, key & someKey, vector<string> & encryptedContent)
{
    unsigned int fileLen = someFile.length();
    for (unsigned int i = 0; i < fileLen; i++)
    {
        string output = "";
        for (unsigned int j = 0; j < someFile[i].length(); j++)
        {
            output.push_back(encryptChar(someFile[i][j], someKey));
        }
        encryptedContent.push_back(output);
    }
}


char encryptChar(char ch, key & someKey)
{
    /*
	Note to self: The following two lines replace an
	entire switch-case statement. The logib behind it
	is that the first character (32 DEC im ASCII table)
	will be replaced with the first character in the
	key list, second with second, and so on.
    */
    int dec = (int)ch;
 	
	/*
		Carriage return (i.e.'return' key)
	*/
    if (dec < 31 || dec > 127)
	return ch;

    return someKey[dec - 31];
}


void outputToDisplay(vector<string> & encryptedContent)
{
    unsigned numRows = encryptedContent.size();
    for (unsigned int i = 0; i < numRows; i++)
        cout << encryptedContent[i] << endl;
}
