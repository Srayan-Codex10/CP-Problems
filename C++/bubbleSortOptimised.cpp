#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> arr, int size)
{
    bool swapped = false;
    for (int i = 1; i <= size - 1; i++)
    {
        for (int j = 0; j <= size - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = false;
            } else {
                swapped = true;
            }
        }
        if(swapped) {
            cout << "Array is sorted";
            break;
        }
    }
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    int size = arr.size();
    bubbleSort(arr, size);
}
