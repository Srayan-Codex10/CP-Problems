/**
 * @author Srayan Ray
 * */
#include <iostream>
#include <cstring>

using namespace std;

int countChars()
{

    int nums = 0;
    int spaces = 0;
    int letters = 0;

    char ch;

    while (ch != '\n')
    {
        // counts numebrs, alphabets , tabs and spaces in the string
        ch = cin.get();
        if (ch >= '0' && ch <= '9')
        {
            nums++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            letters++;
        }
        else if (ch == ' ' || ch == '\t')
        {
            spaces++;
        }
    }
    cout << "Nums: " << nums << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Alphabets: " << letters << endl;

    return 0;
}

int main()
{
    char line[1000];

    char temp;
    int idx = 0;
    while (temp != '#') // terminating character
    {
        // Problem with cin - the program terminates on a whitespace. Does not read further.
        temp = cin.get();   // reads a character from input buffer
        line[idx++] = temp; // stores each character in array
    }
    line[idx] = '\0';
    cout << "Array Value: " << line << endl;
    cin.ignore();
    countChars();
    cin.ignore();
    /* ************************ */

    // this method takes multiple lines or single as input with all characters. add '\0' at end of string
    // delimiter can be changed.
    cin.getline(line, 1000, '.');
    cout << line;

    /* char a[] = {'a', 'v', 'c', '\0'};
    cout << *a << endl;
    cout << a << endl;
    cout << *(a + 2) << endl;

    string arr = "asd";
    for (char c : arr)
    {
        cout << (int)c << " ";
    } */
    return 0;
}