/*
 * Author: Fadi Hanna Al-Kass
 * Project: Private Key Generator
*/


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
 * Private Key Generator
*/
class privateKey
{
public:
    privateKey()
    {
        vals = new char(numChars);
        for (unsigned int i = 32, j = 0; i < 127; i++, j++)
            vals[j] = (char)i;
        randomizeKeyVals();
    }

    /*
     * Return private key list
    */
    char * getKey()
    {
        return vals;
    }

    /*
     * Return private key length
    */
    unsigned int getLength()
    {
        return numChars;
    }

    /*
     * This functions allows access to a specific
     * element in the private key list
    */
    char operator[](unsigned int at)
    {
        return vals[at];
    }

private:
    static const unsigned numChars = 96;
    char * vals;

    /*
     * Since all elements in private key are generated
     * in the order they are listed on the ASCII table,
     * this function is needed to randomize the elements.
     *
     * Note: This function is automatically called in main,
     * and therefore, there is no need for it to be pbulic.
    */
    void randomizeKeyVals()
    {
        srand(time(0));
        for (int i = 0; i < 5; i++)
            for (unsigned int j = 0; j < numChars; j++)
            {
                unsigned int tmpLocation = rand() % numChars;
                char tmpChar = vals[tmpLocation];
                vals[tmpLocation] = vals[j];
                vals[j] = tmpChar;
            }
    }
};


void usage();
void error();
void randomizeList(privateKey, char[96][96]);
void loadKeyToList(privateKey, char[96][96]);
void outputToDisplay(char[96][96]);


int main(int argc, char * args[])
{

    if (argc == 2)
    {
        string command = args[1];
        if (command == "-h" || command == "--help")
            usage();
        else
            error();
    }

   char list[96][96];

   privateKey key;

   randomizeList(key, list);
   loadKeyToList(key, list);

   outputToDisplay(list);
}

void usage()
{
    cout << "This program generates a new private key every time it's run." << endl;
    cout << "To save private key, use output redirection symbol ('>') along with a specified file name." << endl;
    cout << "Usage: keyGen [-h|--help]" << endl;
    exit(0);
}

/*
 * Display an error message upon usage of an
 * invalid command.
 *
 * Note: Since this program does NOT take any
 * arguments, call this function when one or
 * more arguments of any type is passed.
*/
void error()
{
    cout << "Invalid command. Execute program alone or use -h for help." << endl;
    exit(0);
}


/*
 * Initialize @list with 96X96 random elements
 * (chars).
*/
void randomizeList(privateKey key, char list[96][96])
{
    for (unsigned int i = 0; i < 96; i++)
        for (unsigned int j = 0; j < 96; j++)
        {
            char ch = key[rand() % key.getLength()];
            list[i][j] = ch;
        }
}

/*
 * This function is responsible for pulling all
 * the private key elements from @privateKey and
 * store them in @list.
*/
void loadKeyToList(privateKey key, char list[96][96])
{
    for (unsigned int i = 0; i < 96; i++)
        list[i][i] = key[i];
}

/*
 * Display private key on the screen.
*/
void outputToDisplay(char list[96][96])
{
        for (unsigned int i = 0; i < 96; i++)
        {
            for (unsigned int j = 0; j < 96; j++)
                cout << list[i][j];
            cout << endl;
        }
    }
