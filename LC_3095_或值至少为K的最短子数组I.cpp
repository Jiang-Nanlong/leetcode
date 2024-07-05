#include <iostream>
#include <vector>
using namespace std;

// ����һ���Ǹ���������nums����һ������k�����һ������������Ԫ�ذ�λ��Ľ�����ڵ���K����˵����������ر��
// ����nums������ر�ǿ�������ĳ���

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int cur = 0;
            for (int j = i; j < nums.size(); j++) {
                cur |= nums[j];
                if (cur >= k) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,3 };
    int k = 2;
    cout << st.minimumSubarrayLength(nums, k) << endl;
    return 0;
}