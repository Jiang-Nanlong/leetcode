#include <iostream>
#include <vector>
using namespace std;

// LeetCode 3208 ������I����չ�棬�õĻ�������

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int res = 0;
        int alternatingCount = 0;

        for (int i = 0; i < k - 1; ++i) {
            if (colors[i] != colors[i + 1]) {
                alternatingCount++;
            }
        }
        if (alternatingCount == k - 1) {
            res++;
        }

        for (int i = 1; i < n; ++i) {
            // �Ƴ����ڵ�Ԫ��
            if (colors[i - 1] != colors[(i - 1 + 1) % n]) {
                alternatingCount--;
            }
            // �½��봰�ڵ�Ԫ��
            if (colors[(i + k - 2) % n] != colors[(i + k - 1) % n]) {
                alternatingCount++;
            }
            // �жϵ�ǰ�����Ƿ��ǽ�����
            if (alternatingCount == k - 1) {
                res++;
            }
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<int> colors{ 0,1,0,1,0 };
    int k = 3;
    cout << st.numberOfAlternatingGroups(colors, k) << endl;
    return 0;
}