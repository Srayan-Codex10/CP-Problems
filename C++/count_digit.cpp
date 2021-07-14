#include <iostream>
using namespace std;
 int main() {
	 int count_arr[10] = {};
	 string input_string;
	 cin >> input_string;
	 int length = input_string.length();
 
	 for (int i = 0; i < length; i++) {
		 count_arr[(int)input_string[i]-48] += 1; 		//48 for ascii
	 }
 
	 for (int i = 0; i < 10; i++) {
		 cout << i << ' ' << count_arr[i] << endl;
	 }
 
 }