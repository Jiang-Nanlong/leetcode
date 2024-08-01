#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ������cards������ѡ�������е�cnt�����ּ����������ǽ��һ��Ҫ��ż�����������Ľ����

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), [&](int& a, int& b) { return a > b; });
        int res = 0;

        vector<int> odd, even;
        int preodd = 0;
        for (int i : cards) {
            if (i % 2 == 1) {  // ��������֮�ͼ��뵽odd����
                if (preodd != 0) {
                    odd.push_back(preodd + i);
                    preodd = 0;
                }
                else
                    preodd = i;
            }
            else  // ż�����뵽even����
                even.push_back(i);
        }

        int i = 0, j = 0, k = 0;
        int oddnum = odd.size(), evennum = even.size();
        for (i = cnt; i > 0 && (j < oddnum || k < evennum); --i) {
            if (i >= 2) {  // ����������������������ϵ�������ѡ�����Ǽȿ���ѡ������������Ҳ����ѡ��һ��ż��
                if (j < oddnum && k < evennum - 1) {  // ����������鶼����
                    if (odd[j] >= even[k] + even[k + 1]) {
                        res += odd[j++];
                        i -= 1;
                    }
                    else {
                        res += even[k++];
                    }
                }
                else if (j < oddnum) {  // ����odd�������
                    res += odd[j++];
                    i -= 1;
                }
                else {  // ����even�������
                    res += even[k++];
                }
            }
            else if (k < evennum)  // i==1�������ֻ��ѡ��һ��ż�����뵽���
                res += even[k++];
        }
        if (i != 0)  // ������������������飬û���ۼӵ�cnt�����֣�ֱ�ӷ���0
            return 0;
        return res;
    }
};

int main() {
	Solution st;
	vector<int> cards{ 1,2,8,9 };
	int cnt = 3;
	cout << st.maxmiumScore(cards, cnt) << endl;
	return 0;
}