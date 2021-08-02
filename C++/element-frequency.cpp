#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int migratoryBirds(vector<int> arr)
{

    map<int, int> birdCount{{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

    for (const int &n : arr)
    {
        ++birdCount[n];
    }

    std::map<int, int>::iterator max_count =
        std::max_element(birdCount.begin(), birdCount.end(),
                         [](const pair<int, int> &a, const pair<int, int> &b)
                         {
                             return a.second < b.second;
                         });

    return max_count->first;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string input;
    getline(cin, input);

    regex pattern(" ");
    sregex_token_iterator iter(input.begin(), input.end(), pattern, -1);
    sregex_token_iterator end;
    vector<string> arr(iter, end);

    vector<int> arr_input(n);
    for (int i = 0; i < arr_input.size(); ++i)
    {
        arr_input[i] = stoi(arr[i]);
    }

    cout << migratoryBirds(arr_input);
}
