/***
 * @author Srayan Ray
 ***/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void testPrintArray(int *arr)
{
    // cout << sizeof(arr) << endl; //prints size of pointer to array ; 8 bytes
    int n = sizeof(arr) / sizeof(int);
    arr[0] = 100;
    cout << arr; // prints base address of arr
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }
}
// O(n)
int kadaneSubArraySum(int *arr, int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum = currentSum + arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}

// Brute Force O(n3)
int subArraySum(int *arr, int n)
{
    int largestSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subArraySum = 0;
            for (int k = i; k <= j; k++)
            {
                subArraySum += arr[k];
            }
            cout << "Current Sum: " << subArraySum << endl;
            largestSum = max(subArraySum, largestSum);
        }
    }

    return largestSum;
}

// Using prefix sums O(n2)
int subArraySumPrefix(int *arr, int n)
{

    int largestSum = 0;
    int prefix[n] = {0};
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subPrefixSum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
            largestSum = max(subPrefixSum, largestSum);
        }
        cout << "Current Largest Sum: " << largestSum << endl;
    }

    return largestSum;
}

// array rotate -- using deque
void arrayRotate(vector<int> arr, int k)
{
    deque<int> dq(arr.begin(), arr.end());
    for (int i = 0; i < k; i++)
    {
        const auto end = *(dq.end() - 1);
        dq.pop_back();
        dq.push_front(end);
    }
    vector<int> arr_rotated(dq.begin(), dq.end());
    for (vector<int>::iterator it = arr_rotated.begin(); it != arr_rotated.end(); ++it)
    {
        cout << *it << " ";
    }
}

// array rotate - O(n) but with high space complexity.
void rotate(vector<int> arr, int k)
{
    vector<int>::reverse_iterator rev_it;
    vector<int> removed_el;
    vector<int> rotated_arr;
    for (int i = 0; i < k; i++)
    {
        removed_el.push_back(*(arr.end() - 1));
        arr.pop_back();
    }

    for (rev_it = removed_el.rbegin(); rev_it != removed_el.rend(); rev_it++)
    {
        rotated_arr.push_back(*rev_it);
    }
    for_each(arr.begin(), arr.end(), [&rotated_arr](int &v)
             { rotated_arr.push_back(v); });
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    vector<int> arr_v = {1, 3, 5, 7, 9};
    int s = sizeof(arr) / sizeof(int);
    // cout << subArraySumPrefix(arr, s) << endl;
    // cout << subArraySum(arr, s) << endl;
    // cout << kadaneSubArraySum(arr, s) << endl;
    rotate(arr_v, 2);

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

    // int arr[] = {1, 2, 3, 4, 5};
    // int *a = arr; // arr is a address variable with the base address of the array
    //  cout << a << endl; // will print base address of array.
    //  cout << sizeof(arr) << endl; // prints total size of array with each integer as 4 bytes
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