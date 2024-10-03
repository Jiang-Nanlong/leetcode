#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ�����������һ������k��һ�β����п��԰�����һ��Ԫ�ؼ�1�����ִ��k�β������������������ƵԪ�ص����Ƶ����
// ��ʵ���Ǹ������ͣ��ѽ��ݵ�����ͬһˮƽ����Ҫ�Ļ��Ѻ�k֮��Ƚϣ�������������

class Solution {
public:
    //��ʼ��ʱ��һֱ�����˼·���������һ�������������Ǳ����������뵽�᲻��������Խ�磬����һ�������ǡ�
    /*int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            k -= 1LL * (nums[j] - nums[j - 1]) * (j - i);  // k��int�͵ģ��������Ĳ������������������ķ�Χ
            while (k < 0) {
                k += nums[j] - nums[i++];
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }*/
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        long long k1 = (long long)k;  // ����long long������
        for (int i = 0, j = 1; j < nums.size(); j++) {
            k1 -= 1LL * (nums[j] - nums[j - 1]) * (j - i);
            while (k1 < 0) {
                k1 += nums[j] - nums[i++];
            }

            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }


    int maxFrequency1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        long long cost = 0;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            cost += 1LL * (nums[j] - nums[j - 1]) * (j - i);  // ���߼����ǰ�����ֱ�Ϊһ���Ļ��ѣ�Ҳ��Ҫ��longlong
            while (k < cost) {
                cost -= nums[j] - nums[i++];
            }

            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
int main() {
    Solution st;
    vector<int> nums{ 1,4,8,13 };
    int k = 5;
    cout << st.maxFrequency(nums, k) << endl;
    cout << st.maxFrequency1(nums, k) << endl;
    return 0;
}