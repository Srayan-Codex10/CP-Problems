#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

vector<string> split(string input_time)
{

    vector<string> res;
    regex pattern(":");
    sregex_token_iterator iter(input_time.begin(), input_time.end(), pattern, -1);
    sregex_token_iterator end;
    vector<string> tokenised_time(iter, end);

    for (auto &a : tokenised_time)
    {
        res.push_back(a);
    }

    return res;
}

vector<string> filterFormatString(vector<string> tokenised_time)
{
    auto start = tokenised_time[2].find("AM");
    auto start_2 = tokenised_time[2].find("PM");

    if (start != string::npos)
    {
        tokenised_time.push_back(tokenised_time[2].substr(start, string::npos));
        tokenised_time[2].erase(start);
    }

    if (start_2 != string::npos)
    {
        tokenised_time.push_back(tokenised_time[2].substr(start_2, string::npos));
        tokenised_time[2].erase(start_2);
    }

    return tokenised_time;
}

string timeConversion(string s)
{
    int hh = 0, mm = 0, ss = 0;
    string frmt;
    string delimiter = ":";
    vector<string> tokenised_time = filterFormatString(split(s));
    hh = stoi(tokenised_time[0]);
    mm = stoi(tokenised_time[1]);
    ss = stoi(tokenised_time[2]);
    frmt = tokenised_time[3];

    if (frmt == "AM")
    {
        if (hh == 12)
        {
            tokenised_time[0] = "00";
            return (tokenised_time[0] + delimiter + tokenised_time[1] + delimiter + tokenised_time[2]);
        }
        else
        {
            return (tokenised_time[0] + delimiter + tokenised_time[1] + delimiter + tokenised_time[2]);
        }
    }
    else
    {
        if (hh > 0 && hh != 12)
        {
            tokenised_time[0] = to_string(hh + 12);
            return (tokenised_time[0] + delimiter + tokenised_time[1] + delimiter + tokenised_time[2]);
        }
        return (tokenised_time[0] + delimiter + tokenised_time[1] + delimiter + tokenised_time[2]);
    }
}

int main()
{
    // input as HH:MM:SSAM or HH:MM:SSPM
    // return 12 hour format time in 24 hour format
    string input;
    getline(cin, input);

    cout << timeConversion(input);
    return 0;
}