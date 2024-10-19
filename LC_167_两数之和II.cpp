#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] < target)
                i++;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                return { i + 1, j + 1 };
        }
        return {};
    }
};

int main() {
    Solution st;
    vector<int> numbers{ 2,7,11,15 };
    int target = 9;
    vector<int> res = st.twoSum(numbers, target);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}