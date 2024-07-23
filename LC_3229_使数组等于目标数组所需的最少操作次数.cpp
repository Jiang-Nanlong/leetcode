#include <iostream>
#include <vector>
using namespace std;

// ��������������ͬ������nums��target��ÿ�β������԰�nums�е��������е�Ԫ��ͳһ��һ���һ������ʹ��nums�����Ϊtarget��������ٲ�������

// �����˵�����˲�����飬������Ҳû������ô���¡�
// �����ʱ��ֻ������Ӧ���ȼ������������Ԫ��֮���Ӧ�Ĳ�ֵ��Ȼ��ѡ��һ����������ͬ��������ͳһ�޸ġ�
// �����ǰԪ�صĲ�ľ���ֵ����ǰһ��Ԫ�صĲ�ľ���ֵ����ô˵����ǰһ��Ԫ�ض������е�Ԫ��ͳһ��һ���һʱ����ǰλ���޷����㣬����Ҫabs(cur-pre)�β�����
// �����ǰԪ�صĲ�ľ���ֵС��ǰһ��Ԫ�صĲ�ľ���ֵ����ô˵��ǰһ��Ԫ�ػ�ǰ��Ԫ���е�ĳһ��ͳһ��һ���һʱ����ǰλ���Ѿ����������ˡ�

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long res = abs(target[0] - nums[0]);
        for (int i = 1; i < n; i++) {
            int pre = target[i - 1] - nums[i - 1];
            int cur = target[i] - nums[i];
            long long temp = 1LL * pre * cur;
            if (temp > 0) {
                if (abs(cur) < abs(pre))
                    continue;
                else
                    res += abs(cur - pre);
            }
            else {
                res += abs(cur);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3, 5, 1, 2 }, target{ 4, 6, 2, 4 };
    cout << st.minimumOperations(nums, target) << endl;
    return 0;
}