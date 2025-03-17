//
// Created by ������ on 25-3-17.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Ҫ����ʱ�临�Ӷ�O(n)�ķ����������������ĵ��������У���������������������
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        unordered_set<int> uset(nums.begin(), nums.end());
        for (int i: uset) {
            // ���i-1���ڣ���ô�Ͳ���ͳ����i��ʼ�������еĳ����ˣ���Ϊ��i-1��ʼ�������л�ͳ����
            if (uset.find(i - 1) != uset.end())
                continue;

            int j = i + 1;
            while (uset.find(j) != uset.end())
                j++;

            res = max(res, j - i);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 0, 1, 2};
    cout << st.longestConsecutive(nums) << endl;
    return 0;
}
