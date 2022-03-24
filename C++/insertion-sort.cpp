#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int current = arr[i]; // temporarily store the key element to insert into the sorted sequence -- 0 to i-1.
        int prev = i - 1;

        // loop and shift the elements one by one in the sorted sequence to find where to insert the key element
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
}

int main()
{
    vector<int> ar = {5, 4, 3, 2, 1};
    int size = ar.size();
    insertionSort(ar, size);

    for (int k = 0; k < size; k++)
    {
        cout << ar[k] << " ";
    }
    return 0;
}