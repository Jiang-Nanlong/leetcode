#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int n = calories.size();
		int score = 0, sum = accumulate(calories.begin(), calories.begin() + k - 1, 0);

		for (int i = k - 1; i < n; i++) {
			sum += calories[i];
			if (i > k - 1)
				sum -= calories[i - k];

			if (sum < lower) score -= 1;
			else if (sum > upper) score += 1;
		}
		return score;
	}
};

int main() {
	Solution st;
	vector<int> calories{ 1,2,3,4,5 };
	int k = 1, lower = 3, upper = 3;
	cout << st.dietPlanPerformance(calories, k, lower, upper) << endl;
	return 0;
}