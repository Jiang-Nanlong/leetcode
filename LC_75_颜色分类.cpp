//
// Created by cml on 25-4-24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int zero = 0, two = n - 1;

        int i = 0;
        while (i <= two) {
            if (nums[i] == 2) {
                swap(nums[i], nums[two--]);
            } else if (nums[i] == 0) {
                swap(nums[i++], nums[zero++]);
            } else {
                i++;
            }
        }
    }
};

int main() {
    vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution st;
    st.sortColors(nums);
    for (int i: nums)
        cout << i << " ";
    cout << endl;

    return 0;
}
