#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// ['a','a','b','b']
void stringCompress(vector<char> &chars)
{
    string s;
    int char_count = 0;

    int n = chars.size();
    int curnt = 0;
    int ahead = 0;

    while (ahead < n)
    {
        if (chars[curnt] == chars[ahead] && char_count == 0)
        {
            s.push_back(chars[ahead]);
            char_count++;
            ahead++;
        }
        else if (chars[curnt] == chars[ahead])
        {
            char_count++;
            if (ahead == n - 1)
            {
                if (char_count > 9)
                {
                    string count = to_string(char_count);
                    s.push_back(count[0]);
                    s.push_back(count[1]);
                }
                else
                {
                    if (char_count != 1)
                    {
                        s.push_back(to_string(char_count)[0]);
                    }
                }
            }
            ahead++;
        }
        else if (chars[curnt] != chars[ahead])
        {
            curnt = ahead;
            if (char_count > 9)
            {
                string count = to_string(char_count);
                s.push_back(count[0]);
                s.push_back(count[1]);
                s.push_back(chars[ahead]);
                ahead++;
            }
            else
            {
                if (char_count != 1)
                {
                    s.push_back(to_string(char_count)[0]);
                }
                s.push_back(chars[ahead]);
                char_count = 1;
                ahead++;
            }
        }
    }
    chars.clear();

    for (const char c : s)
    {
        chars.push_back(c);
    }
    cout << chars.size();
}

void printLargestString()
{
    int n;
    cin >> n;
    cin.ignore();

    char line[1000];
    char largestLine[1000];

    while (n--)
    {
        cin.getline(line, 1000);
        if ((int)strlen(line) > (int)strlen(largestLine))
        {
            strcpy(largestLine, line);
        }
    }

    cout << "Largest String: " << largestLine << endl;
}

void concatString(char *d, char *s)
{
    cout << strcat(d, s) << endl;
}

int main()
{
    char a[100] = "always";
    char b[100];

    // Calculates length of valid string upto '\0'
    cout << strlen(a) << endl;

    // copy from array to another
    strcpy(b, a);
    cout << b << endl;

    // compare string
    cout << strcmp(a, b) << endl;

    // concatenate strings
    char x[] = "Good";
    char y[] = "Morning";

    // concatString(x, y);

    // printLargestString();

    //  Returns the size of the entire array [including null characters]
    // cout << sizeof(a) / sizeof(char) << endl;

    vector<char> test = {'a', 'a', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    stringCompress(test);

    return 0;
}