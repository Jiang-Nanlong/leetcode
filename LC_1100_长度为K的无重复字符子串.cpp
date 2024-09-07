#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

//����һ���ַ���S���ҳ����г���ΪK�Ҳ����ظ��ַ����Ӵ������㷵��ȫ������Ҫ����Ӵ�����Ŀ

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k)
			return 0;

		unordered_map<char,int> umap;
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			++umap[s[i]];
			if (i >= k && --umap[s[i - k]] == 0)
				umap.erase(s[i - k]);
			if (umap.size() == k)
				res++;
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("havefunonleetcode");
	int k = 5;
	cout << st.numKLenSubstrNoRepeats(s, k) << endl;
	return 0;
}