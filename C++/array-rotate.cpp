/***
 * @author Srayan Ray
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

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