//判断两个字符串是否是同构的
//如果字符串s中的字符可以按某种映射关系替换到t，就说两个字符串是同构的

#include <iostream>
#include <unordered_map>
using namespace std;

//感觉这个题的思路真的不好想，这道题居然是个简单题
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

    //第二次做
    //第一次做的时候居然会觉得难。
    //题目中要求的是每个字符只能映射到一个字符，并且每个字符也只能被一个字符给映射，也就是一对一的关系。
    //开始的时候只用了一个unordered_map，然后在遇到badc和bada这样的用例时就报错了，然后就用了两个map分别映射。
    // 因为前边建立了一对一关系以后，后边如果更换应对关系中的一个字符，两个map中就会有一个出错
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