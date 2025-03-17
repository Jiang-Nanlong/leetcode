//
// Created by 曹孟龙 on 25-3-17.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 主要是得用一种方法表示异位词字符串，开始我想用int32_t中的每一位表示每个字符出现的次数，但是这种只能出现0或1次的，这个题中并没有这样的限制。
// 后来看了0x3f的答案，对每个字符串按字典序排序，异位词字符串排序后的结果是一样的，然后用哈希表保存就行
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > umap;
        for (auto &str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        vector<vector<string> > res(umap.size());
        int i = 0;
        for (auto it = umap.begin(); it != umap.end(); ++it, ++i)
            res[i] = std::move(it->second);

        return res;
    }
};

int main() {
    Solution st;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > res = st.groupAnagrams(strs);
    for (auto &vec: res) {
        for (auto &str: vec)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
