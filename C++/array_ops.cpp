#include <iostream>
#include <fstream>
#include <sstream>
#define N 20

using namespace std;

// Traverse Array
void printArray(int *arr, int size)
{
    cout << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}

// delete from end
int pop(int *arr, int &upper_bound)
{
    if (upper_bound != 0)
    {
        upper_bound--;
    }
    else
    {
        cout << endl;
        cout << "Array is Empty" << endl;
        return -1;
    }
    printArray(arr, upper_bound);
    return 0;
}

int remove(int *arr, int pos, int &upper_bound)
{
    if (upper_bound == 0)
        return -1;

    if (pos == upper_bound)
    {
        pop(arr, upper_bound);
    }
    else
    {
        // left shifting elements starting from delete index
        for (int i = pos; i < upper_bound; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    upper_bound--;
    printArray(arr, upper_bound);
    return 0;
}

// Insert at end of array
int push(int *arr, int &upper_b, int data)
{
    if (upper_b == N - 1)
        return -1;

    arr[upper_b + 1] = data;
    upper_b++;
    return 0;
}

// Insert at index i
int add(int *arr, int &n, int data, int idx)
{
    if (n == N - 1)
        return -1;

    if (idx == n)
        return -1;

    // right shifting the elements after insert position.
    for (int i = n; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }
    cout << endl;
    // printArray(arr, n);
    arr[idx] = data;
    n++;

    return 0;
}

// Read from File
void read_data(int *arr, int &n)
{
    string line;
    fstream file;
    file.open("input.txt", ios::in);
    if (file.is_open())
    {
        cout << "Reading Input from file" << endl;
        while (getline(file, line))
        {
            cout << "Data: " << line;
        }

        stringstream ss(line);
        int num;
        int i = 0;
        while (ss >> num)
        {
            arr[i] = num;
            i++;
        }
        n = i - 1;
        cout << endl
             << "Count: " << n;
    }

    file.close();
}

int main()
{
    int arr[N] = {0};
    int last = 0;
    read_data(arr, last);
    // cout << "Array Size: " << (sizeof(arr) / sizeof(int)) << endl;
    cout << endl;

    push(arr, last, 23);
    printArray(arr, last);
    cout << endl
         << "Count: " << last;

    add(arr, last, 43, 3);
    printArray(arr, last);

    pop(arr, last);
    pop(arr, last);
    remove(arr, 4, last);

    return 0;
}