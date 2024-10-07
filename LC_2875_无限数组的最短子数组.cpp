#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// ����һ�����飬������һ������������������飬Ҳ�������޳��������һ����λ��nums�������������nums�����������
// ���������ҳ���̵������飬������ĺ͵���target

// �뵽�û������ںܼ򵥣���Ҫ�ǲ�֪��Ӧ�ðѿ�ָ���������Ϊ���١�
// ���Ի�ͼ��ʾ��target���ڵ��Ǹ�������һ������m��������nums��������β�������������ƴ����ɣ�
// ���ǿ��Բ�����������m��nums���飬ֻ�����������������ģ���ʵҲ����target��nums����ĺ�ȡ���Ľ��
// ������һ������������nums�����ʾ������ټ���m������nums����ĳ��ȾͿ�����Ľ����

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int m = target / total;
        target = target % total;
        long long sum = 0;
        int minlen = INT_MAX;

        for (int i = 0, j = 0; j < 2 * n; j++) {
            sum += nums[j % n];
            while (sum > target) {
                sum -= nums[(i++) % n];
            }
            if (sum == target) {
                minlen = min(minlen, j - i + 1);
            }
        }
        return minlen == INT_MAX ? -1 : minlen + m * n;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,2,2,1,2,1,2,1,2,1 };
    int target = 83;
    cout << st.minSizeSubarray(nums, target) << endl;
    return 0;
}