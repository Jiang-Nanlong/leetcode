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

    //�ڶ�����
    //��һ������ʱ���Ȼ������ѡ�
    //��Ŀ��Ҫ�����ÿ���ַ�ֻ��ӳ�䵽һ���ַ�������ÿ���ַ�Ҳֻ�ܱ�һ���ַ���ӳ�䣬Ҳ����һ��һ�Ĺ�ϵ��
    //��ʼ��ʱ��ֻ����һ��unordered_map��Ȼ��������badc��bada����������ʱ�ͱ����ˣ�Ȼ�����������map�ֱ�ӳ�䡣
    // ��Ϊǰ�߽�����һ��һ��ϵ�Ժ󣬺���������Ӧ�Թ�ϵ�е�һ���ַ�������map�оͻ���һ������
    bool isIsomorphic1(string s, string t) {
        unordered_map<char, char> umap1, umap2;
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
    string s2("badc"), t2("bada");
    cout << boolalpha << st.isIsomorphic(s1, t1) << endl;
    cout << st.isIsomorphic(s2, t2) << noboolalpha << endl;
    cout << boolalpha << st.isIsomorphic1(s1, t1) << endl;
    cout << st.isIsomorphic1(s2, t2) << noboolalpha << endl;
    return 0;
}