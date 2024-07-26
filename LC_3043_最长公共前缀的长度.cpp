#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// �����������������飬arr1��arr2���ҳ����е�arr1Ԫ�غ�arr2Ԫ����ɵ������������ǰ׺�ĳ��ȡ�
// �����ù�ϣ��洢arr2������ÿһ��Ԫ�ص�����ǰ׺��Ȼ����ͳ��arr1��Ԫ�ص�ÿһ��ǰ׺�ڹ�ϣ�����Ƿ�����ҵ���ͬ��ǰ׺
// ��ʼ�ñ����������ǳ�ʱ��
// 1 <= arr1.length, arr2.length <= 5 * 10^4, 1 <= arr1[i], arr2[i] <= 108

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> uset;
        for (int x : arr2) {
            uset.insert(x);
            while (x) {
                uset.insert(x / 10);
                x /= 10;
            }
        }
        int res = 0;
        for (int x : arr1) {
            int len = 0, t = x;
            for (int i = x; x; x /= 10)
                len++;
            while (len) {
                if (uset.find(t) != uset.end())
                    res = max(res, len);
                t /= 10;
                len--;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> arr1{ 1,10,100 }, arr2{ 1000 };
    cout << st.longestCommonPrefix(arr1, arr2) << endl;
    return 0;
}