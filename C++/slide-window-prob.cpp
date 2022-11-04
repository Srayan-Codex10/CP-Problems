/**
 *
 * n = {1, 4, 3, 4, 5, 10, 12}
 * k = {1, 0, 1, 0}
 *
 * op :
 *
 * 1 0 3 0
 * 4 0 4 0
 * 3 0 5 0
 * 4 0 10 0
 **/
#include <vector>
#include <iostream>

using namespace std;

/**
 * A Sliding window function that outputs an array of windows based on
 * k[i] == 1 , then add n[j] else add 0 , j = 0 1 2 .... n.length-1, i = 0 1 .... k.length-1
 * */
vector<vector<int>> slideWindow(vector<int> n, vector<int> k)
{
    int start = 0;
    int end = k.size() - 1;
    int k_itr = 0;
    int n_itr = 0;
    vector<vector<int>> outlist;
    vector<int> window;
    while (n_itr < n.size())
    {
        if (k_itr <= end)
        {
            if (k[k_itr] == 1)
            {
                window.push_back(n[n_itr]);
            }
            else
            {
                window.push_back(0);
            }

            if (k_itr == end)
            {
                outlist.push_back(window);
                window.clear();
            }
            k_itr++;
            n_itr++;
        }
        else
        {
            k_itr = 0;
            start++;
            n_itr = start;
        }
    }
    return outlist;
}

int main()
{
    vector<int> n = {1, 4, 3, 4, 5, 10, 12};
    vector<int> k = {1, 0, 1, 0};

    vector<vector<int>> op = slideWindow(n, k);

    for (const vector<int> v : op)
    {
        for (const int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}