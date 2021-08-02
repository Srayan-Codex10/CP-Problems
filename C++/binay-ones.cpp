/**
 * @author Srayan Ray
 *  This program prints the maximum number of consecutive 1's found in a binary number, converted from decimal
 * I have used the step division method to find count the quotients and append each count of consecutive 1's 
 * to a count vector
 * */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int q = 0;
    int count = 0;
    vector<int> counts;

    while (n != 0)
    {
        q = n % 2;
        n = n / 2;

        if (q == 1)
        {
            ++count;
        }
        if (q == 0 && count != 0)
        {
            counts.push_back(count);
            count = 0;
        }
        if (n == 0)
        {
            counts.push_back(count);
        }
    }
    if (counts.size() == 0)
    {
        cout << 0;
    }
    else
    {
        auto max = *max_element(counts.begin(), counts.end());
        cout << max;
    }
    return 0;
}