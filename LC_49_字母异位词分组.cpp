//
// Created by ������ on 25-3-17.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ��Ҫ�ǵ���һ�ַ�����ʾ��λ���ַ�������ʼ������int32_t�е�ÿһλ��ʾÿ���ַ����ֵĴ�������������ֻ�ܳ���0��1�εģ�������в�û�����������ơ�
// ��������0x3f�Ĵ𰸣���ÿ���ַ������ֵ���������λ���ַ��������Ľ����һ���ģ�Ȼ���ù�ϣ�������
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
