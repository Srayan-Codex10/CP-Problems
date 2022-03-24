#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr)
{

    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int key = arr[i];
        int index_min = i;
        // find the minimum element in the sequence {current_position to n-1}
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[index_min])
            {
                index_min = j;
            }
        }
        // swap the current element and minimum element at position index_min
        swap(arr[i], arr[index_min]);
    }
}

int main()
{
    vector<int> ar = {5, 3, -2, -5};
    selectionSort(ar);

    for (const int v : ar)
    {
        cout << v << " ";
    }
}