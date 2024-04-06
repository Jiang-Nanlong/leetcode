//�ж������ַ����Ƿ���ͬ����
//����ַ���s�е��ַ����԰�ĳ��ӳ���ϵ�滻��t����˵�����ַ�����ͬ����

#include <iostream>
#include <unordered_map>
using namespace std;

//�о�������˼·��Ĳ����룬������Ȼ�Ǹ�����
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap1;
        unordered_map<char, char> umap2;
        for (int i = 0; i < s.size(); i++) {
            if (umap1.find(s[i]) == umap1.end())
                umap1[s[i]] = t[i];
            if (umap2.find(t[i]) == umap2.end())
                umap2[t[i]] = s[i];

            if (umap1[s[i]] != t[i] || umap2[t[i]] != s[i])
                return false;
        }
        return true;

    }
};

int main() {
    Solution st;
    string s1("egg"), t1("add");
    string s2("foo"), t2("bar");
    cout << boolalpha << st.isIsomorphic(s1, t1) << endl;
    cout << st.isIsomorphic(s2, t2) << noboolalpha << endl;
    return 0;
}