#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// ����һ�����飬�������һ���������е���������Ԫ��֮��ľ���ֵС�ڵ���2����˵����������Ҫ��ģ�������������Ҫ������������Ŀ

// ��ʼ��ʱ����������Ҫ��¼һ�´��������ֵ����Сֵ��Ȼ���ƶ�����ʱֻ��Ҫ�ƶ������ֵ���ұ�һ����Ϳ����ˣ���������Сֵ�Ĳ����С�ڵ���2����
// ����������ʾ�����֣�����������Сֵһ�������ֵ���ұߣ�Ҳ���������ֵ����ߣ���ʱ���Ҫ���������ֵ������Сֵ�Ƴ������ˣ�����ͱȽϸ����ˡ�
// �����������ɽ�����Ĵ��뷢�ֿ�����map��multiset��ʵ�֣���֮ǰ�򵥶���

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        map<int, int> mp;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                if (--mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

    long long continuousSubarrays1(vector<int>& nums) {
        long long res = 0;
        multiset<int> mset;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            mset.insert(nums[j]);
            while (*mset.rbegin() - *mset.begin() > 2) {
                mset.erase(mset.find(nums[i]));
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 35,35,36,37,36,37,38,37,38 };
    cout << st.continuousSubarrays(nums) << endl;
    cout << st.continuousSubarrays1(nums) << endl;
    return 0;
}