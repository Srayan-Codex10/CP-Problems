#include <iostream>
#include <vector>

using namespace std;

void printPairs(int arr[], int n);
void printSubArray(int input[], int n);

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    // printPairs(arr, n);
    printSubArray(arr, n);
}

void printSubArray(int input[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            for (int k = i; k <= j; ++k) //cubic time, not efficient.
            {
                cout << input[k] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void printPairs(int arr[], int n)
{
    // vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i)
    {                                   //Worst case will happen when i = 0 , j = 0
        for (int j = i + 1; j < n; ++j) //print all pairs as (arr[i],arr[i+1]). In this case , (1,2) and (2,1) are considered same.
        {
            // pairs.push_back(make_pair(arr[i], arr[j]));
            cout << "(" << arr[i] << ", " << arr[j] << ")";
        }
        cout << endl;
    }

    /* for (auto &el : pairs)
    {
        cout << el.first << " " << el.second << endl;
    } */
}