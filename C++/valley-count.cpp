/**
 * @author Srayan Ray
 * This is a problem of counting the complete sequence of a valley. 
 * For any given sequence of 'U' and 'D' strings , there is a valid valley if and ony if 
 * for some step 'U' , the current elevation is -1 and adding step will take it to 0. 
 * 
 * For step 'D' , elevation reduces by 1. For step 'U' increases by 1. 
 * */

#include <iostream>
using namespace std;

int countingValleys(int steps, string path)
{
    int elevation = 0;
    int valleyCount = 0;

    for (const char &step : path)
    {
        if (step == 'D')
        {
            --elevation;
        }
        if (step == 'U')
        {
            if (elevation == -1)
            {
                ++elevation;
                ++valleyCount;
            }
            else
            {
                ++elevation;
            }
        }
    }
    return valleyCount;
}

int main()
{
    int steps;
    string path;
    cin >> steps;
    cin.ignore();
    getline(cin, path); //do not give space -- Input is a sequeunce of 'U' and 'D' => 'UUDD' , 'UUUDDUUDUDUD'

    cout << countingValleys(steps, path);

    return 0;
}