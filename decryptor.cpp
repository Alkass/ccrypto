/*
* Author: Fadi Al-Kass
* Project: Text Decryptor
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

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
void decryptContent(file &, key &, vector<string> &);
char decryptChar(char, key&);
void outputToDisplay(vector<string> &);

int main(int argc, char * args[])
{
    if (argc < 3)
        usage();

    key someKey;
    someKey.loadKey(args[1]);

    file someFile;
    someFile.loadFile(args[2]);

    vector<string> decryptedContent;
    decryptContent(someFile, someKey, decryptedContent);

    outputToDisplay(decryptedContent);

}

void usage()
{
    cout << "Usage: encryptor [key-file] [file-name]" << endl;
    exit(EXIT_FAILURE);
}

void decryptContent(file & someFile, key & someKey, vector<string> & decryptedContent)
{
    unsigned int fileLen = someFile.length();
    for (unsigned int i = 0; i < fileLen; i++)
    {
        string output = "";
        for (unsigned int j = 0; j < someFile[i].length(); j++)
        {
            output.push_back(decryptChar(someFile[i][j], someKey));
        }
        decryptedContent.push_back(output);
    }
}

char decryptChar(char ch, key & someKey)
{
    unsigned int keyLen = someKey.length;
    for (unsigned int i = 0; i < keyLen; i++)
        if (someKey[i] == ch)
        {
            return char(i + 31);
        }
    return ch;
}

void outputToDisplay(vector<string> & encryptedContent)
{
    unsigned numRows = encryptedContent.size();
    for (unsigned int i = 0; i < numRows; i++)
        cout << encryptedContent[i] << endl;
}
