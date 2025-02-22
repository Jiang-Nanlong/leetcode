//
// Created by ������ on 25-2-22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // ʱ�临�Ӷ�ΪO(1)��������nums[i]�ķ�ΧΪ[0,100]��������ݷ�Χ̫��Ļ���������unordered_map�滻vector
    int numIdenticalPairs(vector<int> &nums) {
        vector<int> count(101, 0);
        int res = 0;
        for (const int &i: nums) {
            res += count[i]++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 2, 3, 1, 1, 3};
    cout << st.numIdenticalPairs(nums) << endl;
    return 0;
}
