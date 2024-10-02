#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ�������һ���Ǹ�����k������԰������е�ÿһ��Ԫ��i�޸�Ϊ[i-k, i+k]֮�����������
// ��������ֵ�Ķ���Ϊ����������ͬԪ����ɵ�������еĳ��ȡ�

// ����һ�����������⣬��Ϊ������Ԫ�ص�˳��Խ��û��Ӱ�죬����������
// ��Ȼ�Ǵ����⣬��ôʲôʱ��������󴰿ڣ�ʲôʱ�������С�����أ�
// �����е�ÿһ��Ԫ��nums[i]��ά��һ��[nums[i]-k,nums[i]+k]�����䣬Ҫ��һ�δ����ڵ�ֵ����Ϊͬһ������Щֵ������Ӧ���н�����
// ̰�ĵ���ֻҪ���������Ԫ�ص�����ʹ������ұ�Ԫ�ص������н������ɡ�

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            while (nums[j] - k > nums[i] + k) {
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 4,6,1,2 };
    int k = 2;
    cout << st.maximumBeauty(nums, k) << endl;
    return 0;
}