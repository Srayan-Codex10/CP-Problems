#include <iostream>

using namespace std;

bool isPalindrome(const char *ar, int n)
{

    int front = 0;
    int back = n - 1;
    // use two pointers. Check till front is less than back, to prevent same element check and redundant check.
    while (front < back)
    {
        if (ar[front] == ar[back])
        {
            front++;
            back--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string input;
    cin >> input;

    if (isPalindrome(input.c_str(), input.size()))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}