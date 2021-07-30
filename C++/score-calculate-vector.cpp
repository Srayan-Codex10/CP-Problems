#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> breakingRecords(vector<int> scores)
{
    vector<int> result{0, 0};
    int min = 0, max = 0;
    min = scores[0];
    max = scores[0];
    for (int i = 1; i < scores.size(); ++i)
    {
        if (scores[i] > max)
        {
            max = scores[i];
            ++result[0];
        }
        if (scores[i] < min)
        {
            min = scores[i];
            ++result[1];
        }
    }
    return result;
}
int main()
{
    vector<int> res = breakingRecords(vector<int>{3, 4, 21, 36, 10, 28, 35, 5, 24, 42}); // hard-code input here.
    for_each(res.begin(), res.end(), [](int &v)
             { cout << v << " "; });
    return 0;
}