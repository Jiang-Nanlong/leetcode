#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0;
        while (i < j) {
            res = max(res, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,8,6,2,5,4,8,3,7 };
    cout << st.maxArea(nums) << endl;
    return 0;
}