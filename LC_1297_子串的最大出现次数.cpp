#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ����һ���ַ��������һ���Ӵ������Ӵ��в�ͬ��ĸ����ĿС�ڵ���maxLetters���Ӵ�����λ��[minSize, maxSize]֮�䣬�ͳ�����һ���ô���
// �����ַ��������������������ҳ��ִ��������Ӵ��ĳ��ִ�����

// ������������
// �������Ĺؼ��ǣ��������Ӵ��ĳ��ȴ���minSize����ô����Ӵ��и�ɳ���ΪminSize���Ӵ���϶�Ҳ�����㡰�ô�����Ҫ��ģ�������󳤶�ΪminSize���Ӵ�����Ŀ�����ܴ��ڳ���ΪmaxSize���Ӵ�����Ŀ
// ����ֻ��Ҫ���ǳ���ΪminSize���Ӵ��Ƿ������Ӵ��в�ͬ��ĸ����Ŀ�Ƿ�С�ڵ���maxLetters���ɡ�


class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> s_umap;
        unordered_map<char, int> c_umap;
        int n = s.size();
        string str;
        int res = 0;
        for (int i = 0; i < minSize; i++) {
            ++c_umap[s[i]];
            str += s[i];
        }
        if (c_umap.size() <= maxLetters) {
            ++s_umap[str];
            res = 1;
        }
        for (int i = minSize; i < n; i++) {
            str += s[i];
            str.erase(0, 1);
            ++c_umap[s[i]];
            if (--c_umap[s[i - minSize]] == 0)
                c_umap.erase(s[i - minSize]);
            if (c_umap.size() <= maxLetters) {
                res = max(res, ++s_umap[str]);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("aababcaab");
    int maxLetters = 2, minSize = 3, maxSize = 4;
    cout << st.maxFreq(s, maxLetters, minSize, maxSize) << endl;
    return 0;
}