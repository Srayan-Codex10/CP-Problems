#include<bits/stdc++.h>

using namespace std;

int getMaxElemFrequency(vector<int> input) {
    vector<int> max_list;
    int max = 0;
    // iterates over elements in input vector , stores the maximum elements in max_list and returns size. Duplicates inlcuded
    for(vector<int>::iterator itr = candles.begin(); itr!=candles.end();++itr) {
        if (*itr > max) {
            max = *itr;
            if(max_list.size() != 0) {
                max_list.clear();
                max_list.push_back(max);
            } else {
                max_list.push_back(max);
            }
        } else if(max == *itr) {
            max_list.push_back(*itr);
        }
    }
    
    return max_list.size();
}

int main () {

    // input processing to be updated.

    string input_nums;
    string size;

    getline(cin, size);
    getline(cin, input_nums);

    vector<int> input;
    getMaxElemFrequency(input);


}