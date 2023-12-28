#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* �������Ҫ�ж�ransomNote�ܲ�����magazine�е��ַ���ʾ����������magazine�е�ÿ���ַ�ֻ����һ��
* �����Ƚϼ򵥣���ʼ�õ���unordered_map���ֽ�����Ǻܿ죬Ȼ�󻻳�������ر���ˡ�
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.size() > magazine.size()) return false;
		/*
		unordered_map<char,int> ump;
		for(auto &c:magazine) ump[c]++;
		for(auto &c:ransomNote)
			if(--ump[c]<0)
				return false;
		return true;
		*/
		int count[26] = { 0 };
		for (auto& c : magazine) count[c - 'a']++;
		for (auto& c : ransomNote)
			if (--count[c - 'a'] < 0)
				return false;
		return true;
	}
};

int main() {
	Solution st;
	string ransomNote("aa"), magazine("aab");
	cout << boolalpha << st.canConstruct(ransomNote, magazine) << noboolalpha << endl;
	return 0;
}