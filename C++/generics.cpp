/**
 * 
 * @author Srayan Ray
 * */

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArray(vector<T> &arr)
{
    for (const auto &el : arr)
    {
        cout << el << endl;
    }
}

int main()
{

    vector<int> arr_int{1, 2, 3};
    vector<string> arr_string{"A", "B", "C"};

    printArray<int>(arr_int);
    printArray<string>(arr_string);
}