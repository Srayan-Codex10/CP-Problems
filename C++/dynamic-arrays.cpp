#include <vector>
#include <iostream>
#include <regex>

using namespace std;

int main()
{ // hackerrank variable arrays problem
    // will change i/o to read from file. Large inputs may not full fit in stdin
    int n, q;
    string input;
    cin >> n >> q;
    cin.ignore();

    vector<vector<string>> arr;
    regex pattern(" ");
    for (int i = 0; i < n; ++i)
    {
        getline(cin, input);
        int skip = input.substr(0, input.find(" ")).size() + 1;
        sregex_token_iterator iter(input.begin() + skip, input.end(), pattern, -1);
        sregex_token_iterator end;
        arr.push_back(vector<string>(iter, end));
    }
    input.clear();
    for (int i = 0; i < q; ++i)
    {
        getline(cin, input);
        int idx = stoi(input.substr(0, input.find(" ")));
        string el = input.substr((input.find(" ") + 1), string::npos);
        cout << arr[idx][stoi(el)] << endl;
    }
}

/* input 
10 10
3 916135 272188 794963
3 178997 502468 671251
1 122266
3 223511 996043 990104
3 319694 335208 200789
2 867809 273793
1 925358
1 71140
1 862238
1 994309
6 0
5 0
5 0
7 0
5 0
6 0
3 2
3 1
0 0
9 0 */

/* output 
925358
867809
867809
71140
867809
925358
990104
996043
916135
994309

*/