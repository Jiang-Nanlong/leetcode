#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0, right = s.size() - 1;
		while (left <= right) {
			swap(s[left], s[right]);
			left++;
			right--;
		}

	}
};

int main() {
	Solution st;
	vector<char> s{ 'h','e','l','l','o' };
	st.reverseString(s);
	for (auto c : s)
		cout << c << "  ";
	return 0;
}