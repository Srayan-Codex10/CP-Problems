#include <iostream>
#include <vector>
#include <regex>

using namespace std;

vector<int> split(string input)
{
    regex pattern(" ");
    sregex_token_iterator iter(input.begin(), input.end(), pattern, -1);
    sregex_token_iterator end;
    vector<string> arr_input(iter, end);
    vector<int> arr(6);

    for (int i = 0; i < 6; ++i)
    {
        arr[i] = stoi(arr_input[i]);
    }
    return arr;
}

int main()
{
    string input;
    regex pattern(" ");
    int size = 6;
    vector<vector<int>> arr(6);

    for (int i = 0; i < size; ++i)
    {
        arr[i].resize(6);
        string s;
        getline(cin, s);
        arr[i] = split(s);
    }

    vector<vector<int>> hourGlassSum;
    int sum = 0;
    int j = 0;
    int step = 0;
    for (int i = 0; i < 4; ++i)
    {
        vector<int> row_sum;
        while (j <= 5) // sliding sum of first row of each of 16 submatrices. Slide length is 3. Step increments slider to end of row.
        {
            for (j = step; j < 3 + step; ++j)
            {
                sum += arr[i][j];
            }
            row_sum.push_back(sum);
            sum = 0;
            ++step;
        }
        hourGlassSum.push_back(row_sum);
        step = 0;
        j = 0;
    }

    // add middle row elements of submatrix to sum
    for (int i = 1; i < 5; ++i)
    {
        j = 1;
        while (j < 5)
        {
            hourGlassSum[i - 1][j - 1] += arr[i][j];
            ++j;
        }
    }
    //add last row elements of submatrix to sum . use the sliding sum as before for first row.
    for (int i = 2; i < 6; ++i)
    {
        while (j <= 5)
        {
            for (j = step; j < 3 + step; ++j)
            {
                sum += arr[i][j];
            }
            hourGlassSum[i - 2][step] += sum;
            sum = 0;
            ++step;
        }
        step = 0;
        j = 0;
    }

    vector<int> res;

    for (const vector<int> &row : hourGlassSum)
    {
        for (const int &val : row)
        {
            res.push_back(val);
        }
    }

    auto max = *max_element(res.begin(), res.end());
    cout << max;

    return 0;
}