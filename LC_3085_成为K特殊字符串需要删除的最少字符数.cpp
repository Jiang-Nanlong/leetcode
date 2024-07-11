#include <iostream>
#include <vector>
using namespace std;

// ����һ���ַ���word��һ������k������ַ�����ÿ�����ַ����ִ����Ĳ�ľ���ֵ��С�ڵ���k������Ϊ����һ�������ַ�����
// ���ذ��ַ�����������ַ�����Ҫ������ɾ��������

// ��Ϊ����Сд��ĸ��������������ֻ��26����
// Ҫ�뱣֤���������ַ����ִ����Ĳ�ľ���ֵ��С�ڵ���k��ֻ��Ҫ���ĳ��ִ�������С���ִ����Ĳ�С�ڵ���k���ɡ�
// �����������ֻ��26����ȫ�����ñ����ⷨ�����԰�ÿһ�����ִ�����������С�ĳ��ִ���������ַ��ĳ��ִ�������С�ĳ��ִ�����С����ôֱ��ɾ������Ԫ�ء�
// ���Ԫ�صĴ�����ȥ��С���ִ������ڵ���k�ˣ��Ͱ��������k��Ҳ���ǰ�Ԫ�س��ִ�����Ϊ��С���ִ���+k

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int f[26];
        memset(f, 0, sizeof(f));

        for (char c : word)
            f[c - 'a']++;

        vector<int> freq;

        for (int i : f)
            if (i)
                freq.push_back(i);

        int res = INT_MAX;
        for (int i = 0; i < freq.size(); i++) {
            int temp = 0;

            for (int j = 0; j < freq.size(); j++) {
                if (freq[j] < freq[i])  // ���Ԫ�س��ִ���С����С���ִ�����ֱ��ɾ��
                    temp += freq[j];
                else if (freq[j] > freq[i] + k)  // ���Ԫ�س��ִ���-��С���ִ��� >= k���Ͱ��������k��Ҳ���ǰ�Ԫ�س��ִ��������С���ִ���+k
                    temp += (freq[j] - freq[i] - k);
            }
            res = min(res, temp);
        }
        return res;
    }
};

int main() {
    Solution st;
    string word("aabcaba");
    int k = 0;
    cout << st.minimumDeletions(word, k) << endl;
    return 0;
}