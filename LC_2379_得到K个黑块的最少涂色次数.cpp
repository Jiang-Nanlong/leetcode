#include <iostream>
#include <string>
using namespace std;

// ����һ���ַ�����W��B��ɣ��ֱ��ʾ�׿�ͺڿ飬Ҫ���k�������ĺڿ飬�����ٵ��޸Ĵ����Ƕ���

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = 0;
        int count = 0;
        int n = blocks.size();

        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'W')
                count++;
            if (i == k - 1) {
                res = count;
            }
            else if (i >= k) {
                if (blocks[i - k] == 'W')
                    count--;
                res = min(res, count);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string blocks("WBBWWBBWBW");
    int k = 7;
    cout << st.minimumRecolors(blocks, k) << endl;
    return 0;
}