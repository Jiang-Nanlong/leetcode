#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组，至少包含两个元素，删除数组中的前两个，一次操作的分数是前两个的和，在确保每次操作的分数都相同的前提下，最多能操作多少次

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int count = 0, sum = nums[0] + nums[1];
        int i = 0;
        while (i + 1 < nums.size()) {
            if (nums[i] + nums[i + 1] != sum)
                return count;
            else {
                count++;
                i += 2;
            }
        }
        return count;
    }

    // 第二次做
    int maxOperations1(vector<int>& nums) {
        int count = 0, score = nums[0] + nums[1];
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] + nums[i - 1] == score) {
                count++;
                i += 2;
            }
            else
                return count;
        }
        return count;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3,2,1,4,5 };
    cout << st.maxOperations(nums) << endl;
    cout << st.maxOperations1(nums) << endl;
    return 0;
}