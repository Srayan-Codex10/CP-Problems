#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cin >> n; // number of contacts
    cin >> ws;
    string s;
    int number;
    // vector<pair<string, int>> phonebook;
    map<string, int> phonebook;

    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        string name = s.substr(0, s.find(" "));
        number = stoi(s.substr(s.find(" "), string::npos));
        // phonebook.push_back(make_pair(name, number));
        phonebook[name] = number;
    }

    /* while (getline(cin, s))
    {
        auto it = find_if(phonebook.begin(), phonebook.end(),
                          [&s](const pair<string, int> &p)
                          { return p.first == s; });
        if (it != phonebook.end())
        {
            cout << it->first << "=" << it->second << endl;
        }
    } */
    // gives TLE

    while (cin >> s)
    {
        auto it = phonebook.find(s);
        if (it != phonebook.end())
        {
            cout << it->first << "=" << it->second << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
