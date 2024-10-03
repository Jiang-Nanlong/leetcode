#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// ����һ����������nums��һ������x��ÿһ�β�����ֻ���Ƴ�����������ߵ�Ԫ�غ����ұߵ�Ԫ�أ�xֵҲҪ��ȥ��Ӧ��ֵ��
// ���xǡ�ü�Ϊ0���򷵻���С�����������򷵻�-1.

// ������������дճ�x��������ֱ���������дճ�accumulate(nums)-x�������Ͳ��ÿ�������������ɾ���ˡ�

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int sum = 0;
        int maxlen = -1;  // ��ʼ��maxlen=0�ˣ�������maxlen=0�ͷ���-1���������ԣ���Ϊ�ڽ��������ǰ���£�maxlenȷʵ���ܻ����0
        for (int i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (i <= j && sum > target) { // ����Ҫע��i��j��λ�ã���Ϊtarget�����Ǹ���
                sum -= nums[i++];
            }
            if (sum == target)
                maxlen = max(maxlen, j - i + 1);
        }
        return maxlen == -1 ? -1 : nums.size() - maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309 };
    int x = 134365;
    cout << st.minOperations(nums, x) << endl;
    return 0;
}