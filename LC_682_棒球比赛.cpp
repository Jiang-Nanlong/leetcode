#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        vector<int> vec;
        for (string& s : operations) {
            if (s != "C" && s != "D" && s != "+") {
                int num = stoi(s);
                vec.push_back(num);
            }
            else if (s == "C") {
                vec.pop_back();
            }
            else if (s == "D") {
                vec.push_back(vec.back() * 2);
            }
            else {
                auto it = vec.rbegin();
                int temp = *it++;
                temp += *it;
                vec.push_back(temp);
            }
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};

int main() {
	Solution st;
	vector<string> operations{ "5","-2","4","C","D","9","+","+" };
	cout << st.calPoints(operations) << endl;
	return 0;
}