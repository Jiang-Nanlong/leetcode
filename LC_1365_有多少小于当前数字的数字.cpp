
//����һ�����飬����������ÿ��Ԫ��nums[i]��ͳ�������б���С�����ֵ���Ŀ

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int hash[101] = { 0 };
        for (int i = 0; i < temp.size(); i++) { //�����Ǵ�ǰ��������ģ�������ͬ��ֱ����������ʵ�����ԴӺ���ǰ������������ͬ��Ҳ��ǰ�ߵ��Ǹ���������
            if (i > 0 && temp[i] == temp[i - 1]) continue;
            hash[temp[i]] = i;
        }
        //����д������
        /*for (int i = nums.size() - 1; i >= 0; i--) {
            hash[temp[i]] = i;
        }*/

        for (auto& i : nums) {
            i = hash[i];
        }
        return nums;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8,1,2,2,3 };
    vector<int> res = st.smallerNumbersThanCurrent(nums);
    for (auto& i : res)
        cout << i << "  ";
    return 0;
}