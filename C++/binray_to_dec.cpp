#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int binaryToDecimal(string s)
{
    // your code goes here
    int decimal_val = 0;
    int index = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int num = s[i] - '0';
        decimal_val += num * pow(2, index);
        index++;
    }
    return decimal_val;
}

int main()
{

    cout << binaryToDecimal("111");
}