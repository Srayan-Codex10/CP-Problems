#include <vector>
#include <iostream>
using namespace std;
int binarySearch(vector<int> arr, int key, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr{1, 2, 15, 20, 39, 45};
    int start = 0;
    int end = arr.size() - 1;
    int key;
    cin >> key;
    cout << binarySearch(arr, key, start, end);
}