#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����������������nums1��nums2��nums1��nums2������Ԫ�أ������Ƴ�������Ԫ�أ�ʣ��nums1��nums2֮���Ԫ�ز��Ϊx�����ҳ���С��x

class Solution {
public:
    // ��һ����ö�ٷ���Ҳ���Ǳ�������ʾ��nums1�ĳ������Ϊ200����ģ���󣬿���ֱ���ñ���
    // Ҳ�����ȶ�������������Ȼ����ȥ��nums1�е�����Ԫ�أ��ж�ʣ��Ԫ����nums2֮���ÿ�����ǲ��Ƕ����x��
    // ����ǵĻ��Ϳ�����Ϊ��Сx�ı�ѡ��������Ǿ�˵������ȥ�������������Ǳ���ȥ����������
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int minX = INT_MAX;

        for (int i = 0; i < nums1.size() - 1; i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                vector<int> temp(nums1);
                temp.erase(temp.begin() + j);
                temp.erase(temp.begin() + i);

                int pre = INT_MAX;
                for (int k = 0; k < nums1.size() - 2; k++) {
                    if (k == 0)
                        pre = nums2[k] - temp[k];
                    else {
                        if (nums2[k] - temp[k] != pre) {
                            pre = INT_MAX;
                            break;
                        }
                    }
                }
                minX = min(minX, pre);
            }
        }
        return minX;
    }

    // ��Ϊnums1ֻ��nums2������Ԫ�أ���ô������Ԫ�ؼ����Ƕ���nums1����С��ǰ����Ԫ���У�ǰ����Ԫ���л�����ʣһ��Ԫ�أ���ô����ֻ��Ҫ����ǰ����Ԫ�ؼ���
    // ����ǰ����Ԫ������һ��������Ϊȥ������Ԫ��֮���nums1�����е���СԪ�أ�Ȼ���nums2[0]����diff��Ȼ�����ж�ʣ���nums1��nums2֮���ǲ��ǲ�ֵ��ͬ��
    // ��Ϊ���ﲢû����ȥ����������ֻ��ѡ����nums1����С������Ϊ��ʼ������nums2һ�����������С����ʼ��nums1������Ӽ�������ֻ��Ҫ�ж�nums2�ǲ���nums1���Ӽ����ɡ�
    int minimumAddedInteger1(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 2; i > 0; i--) {  // ����ֻ��Ҫ�ж�nums[2]��nums[1]�����������������ȥ������Ԫ�غ��nums1�������СԪ�أ���ônums[0]�϶�����
            // ��ΪҪ����С��diff�����Ե������nums1��ǰ����Ԫ�أ����ȱ�����ģ�Ȼ��nums2[0]-���nums1[i]����С��diff
            int diff = nums2[0] - nums1[i];
            int j = 0, k = i;
            while (k < nums1.size() && j < nums2.size()) {
                if (nums1[k] + diff == nums2[j])
                    j++;
                k++;
            }
            if (j == nums2.size())
                return diff;
        }
        return nums2[0] - nums1[0];
    }
};

int main() {
    Solution st;
    vector<int> nums1{ 4, 20, 16, 12, 8 }, nums2{ 14, 18, 10 };
    cout << st.minimumAddedInteger(nums1, nums2) << endl;
    cout << st.minimumAddedInteger1(nums1, nums2) << endl;
    return 0;
}