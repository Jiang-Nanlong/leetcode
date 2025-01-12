//
// Created by ������ on 25-1-12.
//
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

// ����һ�����飬���ذ�λ��������0�����ϵĳ���

// ��λ��������0����ʵ����Ҫ��λ���Ժ�Ľ������1����ô�����ת��Ϊ�˰�λ���Ժ�ĳ��λ��Ϊ1����ôֻ��Ҫͳ���ж��ٸ������ڸ�λ�ö�����λΪ1����

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int max_val = 0;
        for (int i: candidates)
            max_val = max(max_val, i);

        int n = bitset<32>(max_val).size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int num: candidates)
                count += num >> i & 1;
            res = max(res, count);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> candidates{16, 17, 71, 62, 12, 24, 14};
    cout << st.largestCombination(candidates) << endl;
    return 0;
}
