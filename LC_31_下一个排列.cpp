#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// ��ʼ��ֻ�뵽��Ҫnums[j]>nums[i]ʱ���л�������û�뵽��ߵĻ�Ҫ��������
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {  // ������ѭ��Ҳ��˵������ʼ��ʱ�����ǰ�i�Ӻ���ǰ������j��ʼ��Ϊi-1��jҲ��ǰ������
            for (int j = nums.size() - 1; j > i; j--) {  // ����������4, 2, 0, 2, 3, 2, 0�������ʱ�ͳ����ˡ���������ȷʵ���ԣ���ǰԪ��nums[i]Ӧ�ú�λȨ��С�Ļ�����������λȨ����ģ�Ҳ����Ӧ�ú���Ÿ���Ľ��л���
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        // ���е�����˵�����������ǴӴ�С���еģ�ֱ�����������
        reverse(nums.begin(), nums.end());
    }
};


int main() {
    Solution st;
    vector<int> nums{ 4, 2, 0, 2, 3, 2, 0 };
    st.nextPermutation(nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}