#include<iostream>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        auto bin = [](int x) {
            string s = bitset<32>(x).to_string();
            return s.substr(s.find('1'));
            };
        return bin(stoi(date.substr(0, 4))) + "-" +
            bin(stoi(date.substr(5, 2))) + "-" +
            bin(stoi(date.substr(8, 2)));
    }
};


int main() {
    Solution st;
    string date("2080-02-29");
    cout << st.convertDateToBinary(date) << endl;
    return 0;
}