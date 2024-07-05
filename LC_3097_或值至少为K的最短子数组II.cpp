#include <iostream>
#include <vector>
using namespace std;

// ��LeetCode 3095 ��ֵ���� K �����������I һ����Ҫ�󣬲�����������������
// ����һ�����������⣬�о�������˼·̫�����ˡ�
// ����������İ�λ������ͬʱ��һ������bit����������ÿ��Ԫ��ÿ��bitλΪ1�Ĵ������Ա�����С����ʱ�á�
// nums[i]<=1e9������ɶ�����Ҳ����2^30������bit���鹲30��Ԫ�ء�
// һ��������İ�λ�������ڵ���k�ˣ��Ϳ�ʼ��С���ڡ���ȥÿ��Ԫ�ص�ÿ��bitλ�������е�1�ĸ��������Ϊ0�ˣ�˵���ڴ��ڵ���߽磬��bitλ�Ѿ�û��1�ˣ�
// �Ϳ��԰�ǰ�߰�λ��Ľ���ڸ�bitλ��Ϊ0�ˡ�
// ����˼·��һ���������ǰ�λ��Ľ�����ǵ����ģ�ֻҪ�����е�ĳ��λ��֮ǰ����һ��Ԫ���ڸ�bitλΪ1�����������ڸ�λ�õİ�λ������Ϊ1

class Solution {
public:
    void add_bit(vector<int>& bit, int num) {
        for (int i = 1, j = 0; i <= num; i <<= 1, j++)
            if (num & i)
                bit[j]++;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bit(30, 0);
        int res = INT_MAX;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum |= nums[i];
            add_bit(bit, nums[i]);
            while (j <= i && sum >= k) {
                res = min(res, i - j + 1);
                for (int t = 1, id = 0; t <= nums[j]; t <<= 1, id++) {
                    if (t & nums[j]) {
                        bit[id]--;
                        if (bit[id] == 0)
                            sum ^= t;
                    }
                }
                j++;
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