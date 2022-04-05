#include <iostream>
#include <string>

using namespace std;

bool isPermutation(string A, string B)
{
    size_t idx;
    for (const char c : B)
    {
        idx = A.find(c);
        if (idx == std::string::npos)
        {
            return false;
        }
        else
        {
            A[idx] = '\0';
        }
    }
    return true;
}

int main()
{

    string A = "aab";
    string B = "aba";

    cout << isPermutation(A, B);

    return 0;
}