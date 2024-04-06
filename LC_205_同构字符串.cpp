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
};

int main() {
    Solution st;
    string s1("egg"), t1("add");
    string s2("foo"), t2("bar");
    cout << boolalpha << st.isIsomorphic(s1, t1) << endl;
    cout << st.isIsomorphic(s2, t2) << noboolalpha << endl;
    return 0;
}