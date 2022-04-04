#include <vector>
#include <iostream>

using namespace std;

int maxArrayElement(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int *arr, int n, int max_range)
{
    int countArr[max_range + 1] = {0};
    for (int idx = 0; idx < n; idx++)
    {
        countArr[arr[idx]]++;
    }

    int arr_idx = 0;

    for (int k = 0; k <= max_range; k++)
    {
        int freq = countArr[k];
        while (freq > 0)
        {
            arr[arr_idx] = k;
            freq--;
            arr_idx++;
        }
    }
    for (int x = 0; x < n; x++)
    {
        cout << arr[x] << " ";
    }
}

int main()
{

    int ar[] = {2, 3, 6, 6, 1, 10, 4};
    int size = sizeof(ar) / sizeof(int);
    int max_arr_el = maxArrayElement(ar, size);
    countingSort(ar, size, max_arr_el);
}