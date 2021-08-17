/**
 * @author Srayan Ray
 * 
 * Just for practice and understanding how bubble sort works
 * */

#include <iostream>
#include <vector>
using namespace std;

void countSwaps(vector<int> a)
{
    int swaps = 0;
    bool swapped = false;
    int end = a.size();

    for (int i = 0; i < end; ++i)
    {

        swapped = false;
        // here the limit is end-i-1 
        //The reason is , the largest element in each pass always gets to the end of the array. So , the length of pass is reduced. 
        for (int j = 0; j < end - i - 1; ++j) 
        
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
                ++swaps;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    cout << "Array is sorted in " << swaps << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[end - 1] << endl;
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    countSwaps(a);
}