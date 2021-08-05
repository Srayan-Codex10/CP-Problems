#include <iostream>

using namespace std;

class Box
{
private:
    int l, b, h;

public:
    Box()
    {
        l = 0;
        b = 0;
        h = 0;
    }

    Box(int length, int breadth, int height)
    {
        h = height;
        l = length;
        b = breadth;
    }

    Box(Box &B)
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }

    long long CalculateVolume()
    {
        long long res = (long long)l * (long long)b * (long long)h;
        return res;
    }
    bool operator<(Box &B1)
    {
        if (this->l < B1.l)
        {
            return true;
        }
        else if (this->b < B1.b && this->l == B1.l)
        {
            return true;
        }
        else if (this->h < B1.h && this->l == B1.l && this->b == B1.b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

ostream &operator<<(ostream &out, Box &B)
{
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}

int main()
{
    return 0;
}