
//����һ�����飬����������ÿ��Ԫ��nums[i]��ͳ�������б���С�����ֵ���Ŀ

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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

    //�ڶ�����
    //��ʵ���Ǽ�¼���������ÿ��Ԫ�ص�һ�γ��ֵ�λ��
    vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());

        unordered_map<int, int> umap;
        for (int i = 0; i < temp.size(); i++) {
            if (umap.count(temp[i]) == 0)
                umap.insert({ temp[i], i });
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = umap[nums[i]];
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8,1,2,2,3 };
    vector<int> res = st.smallerNumbersThanCurrent(nums);
    for (auto& i : res)
        cout << i << "  ";

    cout << endl;
    vector<int> nums1{ 8,1,2,2,3 };
    vector<int> res1 = st.smallerNumbersThanCurrent1(nums1);
    for (auto& i : res1)
        cout << i << "  ";
    return 0;
}