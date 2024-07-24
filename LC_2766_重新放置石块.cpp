#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
		unordered_set<int> uset(nums.begin(), nums.end());
		int n = moveFrom.size();
		for (int i = 0; i < n; i++) {
			int from = moveFrom[i], to = moveTo[i];
			if (uset.find(from) != uset.end()) {
				uset.erase(from);
				uset.insert(to);
			}
		}
		vector<int> res(uset.begin(), uset.end());
		sort(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,6,7,8 }, moveFrom{ 1,7,2 }, moveTo{ 2,9,5 };
	vector<int> res = st.relocateMarbles(nums, moveFrom, moveTo);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}