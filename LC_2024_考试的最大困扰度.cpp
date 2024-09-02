#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ����һ���ַ�����������T��F����һ��������k�����β����п��԰��ַ����е��ַ�T�޸�ΪF �� ��F�޸�ΪT�����ڲ�����k�β���������£����������T��F����Ŀ��

// ����һ�����������⣬ͳ�ƴ�����һ���ַ�������������˵F����F������С�ڵ���kʱ��˵���ڵ�ǰ�����ڵ�F������k�β����ڶ����T����ʱ��T�����������������right-left+1.
// ���������F����������kʱ��˵��������k�β����аѴ����ڵ�F�����T����ʱ���Ҫ��С���ڡ�
// ��ͳ���ַ�Tʱ������Ҳ��һ����

class Solution {
public:
    int helper(string& answerKey, char c, int k) {
        int n = answerKey.size();
        int count_c = 0, res = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            if (answerKey[j] == c)
                count_c++;

            while (count_c > k) {
                if (answerKey[i++] == c)
                    count_c--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, 'T', k), helper(answerKey, 'F', k));
    }
};

int main() {
    Solution st;
    string answerKey("TTFTTFTT");
    int k = 1;
    cout << st.maxConsecutiveAnswers(answerKey, k) << endl;

	return 0;
}