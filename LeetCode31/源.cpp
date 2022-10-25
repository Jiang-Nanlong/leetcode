#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//[1,3,2]  output:[3,1,2]  right:[2,1,3]
/*
    ��һ���뵽����ע�͵��ķ��������Ƕ���[1,3,2]����
    �����ֲ�������һ�ַ�ʽ
    ���ȵ�����ҵ�һ����i�������������ߵ��Ǹ���С��
    Ȼ������ͷ����Ŀ�ʼ�ҵ���һ�����������j��Ȼ�󽻻����������i����������������
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       /* int lenght = nums.size();
        int i;
        for (i = lenght - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) break;
        }
        if(i>0) swap(nums[i], nums[i + 1]);
        sort(nums.begin() + i + 1, nums.end());*/

        int length = nums.size();
        int i, j;
        for (i = length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }

        if (i >= 0) {
            j = length - 1;
            while (j >= 0) {
                if (nums[j] > nums[i]) break;
                j--;
            }
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());

    }
};