#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> duplicates(int arr[], int n)
{
    // code here
    int curnt = 0;
    int ahead = 1;
    vector<int> dup_arr;
    vector<int>::iterator it;
    while (curnt < (n - 1))
    {
        it = find(dup_arr.begin(), dup_arr.end(), arr[curnt]);
        if (it == dup_arr.end())
        {
            if (ahead != n && arr[curnt] == arr[ahead])
            {
                dup_arr.push_back(arr[curnt]);
                curnt++;
                ahead = curnt;
            }
        }
        if (ahead == n)
        {
            curnt++;
            ahead = curnt;
        }
        ahead++;
    }
    if (dup_arr.empty())
    {
        dup_arr.push_back(-1);
    }
    sort(dup_arr.begin(), dup_arr.end());
    return dup_arr;
}

int main()
{
    int arr[] = {17, 7, 17, 0, 13, 7, 1, 17, 7, 17, 5, 2, 19, 15, 8, 4, 17, 5, 4, 6, 13, 5, 7};
    int size = sizeof(arr) / sizeof(int);

    vector<int> data = duplicates(arr, size);
    for (int val : data)
    {
        cout << val << " ";
    }
}

/* 17, 7, 17, 0, 13, 7, 1, 17, 7, 17, 5, 2, 19, 15, 8, 4, 17, 5, 4, 6, 13, 5, 7*/