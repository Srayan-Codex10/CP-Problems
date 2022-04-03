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

/**
 * !!Problem:
 *  Give a string of paths as SWNE , [South, West, North , East] in 2-D coordinate,
 *  print the shortest path between initial and final position.
 *  Example: SNNNEWE
 *  Output: NNE  [x=1, y=2]
 * */
int printShortestRoute()
{

    char path[1000];
    cin.getline(path, 1000);

    int x = 0, y = 0;
    for (int i = 0; path[i] != '\0'; i++)
    {
        switch (path[i])
        {

        case 'S':
            y--;
            break;

        case 'N':
            y++;
            break;

        case 'E':
            x++;
            break;

        case 'W':
            x--;
            break;

        default:
            cout << "Invalid Route";
        }
    }

    cout << "X: " << x << ", "
         << "Y: " << y << endl;

    if (x >= 0 && y >= 0)
    {
        while (y--)
        {
            cout << 'N';
        }
        while (x--)
        {
            cout << 'E';
        }
    }
    else if (x <= 0 && y >= 0)
    {
        while (y--)
        {
            cout << 'N';
        }
        while (x++)
        {
            cout << 'W';
        }
    }
    else if (x <= 0 && y <= 0)
    {
        while (y++)
        {
            cout << 'S';
        }
        while (x++)
        {
            cout << 'W';
        }
    }
    else if (x >= 0 && y <= 0)
    {
        while (y++)
        {
            cout << 'S';
        }
        while (x--)
        {
            cout << 'E';
        }
    }

    return 0;
}

int main()
{

    printShortestRoute();

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