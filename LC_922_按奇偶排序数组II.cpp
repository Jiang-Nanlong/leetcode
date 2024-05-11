#include <iostream>
#include <vector>
using namespace std;

//����һ��nums���飬������һ����������һ����ż�������ڰ�����������λ����Ϊ������ż��λ����Ϊż��

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i % 2 == 0) {
                if (nums[i] % 2 == 0)
                    continue;
                else {
                    int begin = i + 1;
                    while (nums[begin++] % 2 == 1);
                    swap(nums[i], nums[begin - 1]);
                }
            }
            else {
                if (nums[i] % 2 == 1)
                    continue;
                else {
                    int begin = i + 1;
                    while (nums[begin++] % 2 == 0);
                    swap(nums[i], nums[begin - 1]);
                }
            }
        }
        return nums;
    }

    //���Ǵ�������¼�Ĵ𰸣�˼·Ҳ�������������Ҹо������Ǹ����ã�����ʹ���˶���Ŀռ�
    vector<int> sortArrayByParityII1(vector<int>& nums) {
        vector<int> result(nums.size());
        int evenIndex = 0; // ż���±�
        int oddIndex = 1;  // �����±�
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                result[evenIndex] = nums[i];
                evenIndex += 2;
            }
            else {
                result[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return result;
    }

    //������һ������һ��ż������ôֻҪ��������ż���е�һ��λ�ö�Ӧ�ã�ʣ���һ��Ҳ�Ͷ�Ӧ����
    vector<int> sortArrayByParityII2(vector<int>& nums) {
        int oddIndex = 1;  //�����±�
        for (int i = 0; i < nums.size(); i += 2) {  //ֻ���������ż��λ
            if (nums[i] % 2 == 1) {       // �����ż��λ����������
                while (nums[oddIndex] % 2 == 1)
                    oddIndex += 2;       // ������λ��һ��ż��
                swap(nums[i], nums[oddIndex]); // �滻
            }
        }
    return nums;
    }

};

int main() {
    Solution st;
    vector<int> nums = { 4, 2, 5, 7 };
    vector<int> res = st.sortArrayByParityII(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    vector<int> nums1 = { 4, 2, 5, 7 };
    vector<int> res1 = st.sortArrayByParityII1(nums1);
    for (int i : res1)
        cout << i << " ";
    cout << endl;

    vector<int> nums2 = { 4, 2, 5, 7 };
    vector<int> res2 = st.sortArrayByParityII2(nums2);
    for (int i : res2)
        cout << i << " ";
    cout << endl;
    
    return 0;
}