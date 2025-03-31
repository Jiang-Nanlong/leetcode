//
// Created by ������ on 25-3-31.
//
#include <iostream>
#include <vector>
using namespace std;

// ����һ��δ������������飬�ҳ�����û�г��ֵ���С��������
// Ҫ��ʱ�临�Ӷ�ΪO(n)����������ռ�Ľ������

// �������ĳ��ȣ���ÿ�������鳤�ȷ�Χ�ڵ��������ҵ�����ӦӦ���ڵ�λ�ã�����1�����ڵ�0��λ�ã�2�����ڵ�1��λ��

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            // ����Ҫ��whileѭ������Ϊ�����if�Ļ����½������������ֻ�û������ȷ��λ�ã�����ʱ��i�������ˣ��ͻ�������ǰ�½�������������
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};

int main() {
    Solution st;
    vector<int> nums{3, 4, -1, 1};
    cout << st.firstMissingPositive(nums) << endl;
    return 0;
}
