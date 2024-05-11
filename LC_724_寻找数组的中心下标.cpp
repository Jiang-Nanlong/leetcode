#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 自己没做出来
    // 下边是我自己写的代码
    // 这个方法不行，如果向-1,-1,-1,-1,-1,0这种，只会一直向右移动左指针
    /*int pivotIndex(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int sumleft = nums[left], sumright = nums[right];
        while (left < nums.size() && right >= 0 && left <= right) {
            if (left == right && sumleft == sumright) break;
            if (sumleft <= sumright) {
                sumleft += nums[++left];
            }
            else
                sumright += nums[--right];
        }
        if (sumleft == sumright)
            return left;
        return -1;
    }*/
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int& i : nums)
            sum += i;
        int leftsum = 0, rightsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            leftsum += nums[i];
            rightsum = sum - leftsum + nums[i];
            if (leftsum == rightsum)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution st;
    vector<int> nums{ -1,-1,-1,-1,-1,0 };
    cout << st.pivotIndex(nums) << endl;
    return 0;
}