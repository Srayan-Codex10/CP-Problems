#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void testPrintArray(int *arr)
{
    // cout << sizeof(arr) << endl; //prints size of pointer to array ; 8 bytes
    int n = sizeof(arr) / sizeof(int);
    arr[0] = 100;
    cout << arr; //prints base address of arr
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }
}

int main()
{

    /*  int marks[100] = {0}; //initialize //create

    int n;
    cin >> n;
    marks[0] = -1; //update
    for (int i = 1; i < n; ++i)
    {
        cin >> marks[i];
        marks[i] *= 2; //modify
    }

    for (int i = 0; i < 100; ++i)
    {
        cout << marks[i] << ", "; //output
    } */

    //int arr[] = {1, 2, 3, 4, 5};
    //int *a = arr; // arr is a address variable with the base address of the array
    // cout << a << endl; // will print base address of array.
    // cout << sizeof(arr) << endl; // prints total size of array with each integer as 4 bytes
    /*  testPrintArray(a);
    int num_el = sizeof(arr) / sizeof(int);
    for (int i = 0; i < num_el; ++i)
    {
        cout << arr[i] << endl; // arr[i] is the same as *(arr+i)
    }
    for (int i = 0; i < num_el; ++i)
    {
        cout << *(arr + i) << endl;
    }
    return 0; */
}