#include <iostream>
using namespace std;

// Traverse Array
void printArray(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Insert at end of array
int push(int *arr, int &upper_b, int n, int data)
{
    if (upper_b == n)
        return -1;

    arr[upper_b + 1] = data;
    upper_b++;
}

int main()
{
    int data;
    int N = 20;
    int arr[N] = {0};
    int last = 0;

    // cout << "Array Size: " << (sizeof(arr) / sizeof(int)) << endl;

    // Fill array
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        last = i;
    }

    
}