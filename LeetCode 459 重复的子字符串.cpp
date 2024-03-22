#include <iostream>
#include <string>
using namespace std;

//这个题居然是一个简单题，这也太难了

class Solution {
public:
	/*bool repeatedSubstringPattern(string s) {  //移动匹配 时间复杂度O(n)
		string t = s + s;
		t.erase(t.begin());
		t.erase(t.end() - 1);
		if (t.find(s) != -1) return true;
		return false;

	}*/

	//KMP做法  时间复杂度O(n)
	bool repeatedSubstringPattern(string s) {
		if (s.size() == 0) return false;
		int* next = new int[s.size()];
		getNext(s, next);
		if ((next[s.size() - 1] != 0) && (s.size() % (s.size() - next[s.size() - 1]) == 0))   //这里最后的最小重复子串就是前s.size() - next[s.size() - 1]个元素。  
			//next[s.size() - 1] != 0是为了防止出现abac这种情况，这种情况下如果没有这个条件会判断为有重复子串，其实是没有的。
			return true;
		return false;
	}
private:
	void getNext(const string& s, int* next) {
		int i = 0;
		next[0] = 0;
		for (int j = 1; j < s.size(); j++) {
			while (i > 0 && s[i] != s[j])
				i = next[i - 1];
			if (s[i] == s[j])
				i++;
			next[j] = i;
		}
	}

public:
	//第二次做还是没有做出来，两个方法一个也没想起来
	//看了答案以后才想起来。如果一个字符串是由重复子串构成的，那么它一定存在相同的最长相等前后缀，根据前缀和后缀的位置关系，可以观察到他们不重叠的位置就应该是要求的子字符串。
	bool repeatedSubstringPattern1(string s) {
		string t = s + s;
		t.erase(t.begin());
		t.erase(t.end() - 1);
		if (t.find(s) != -1)
			return true;
		return false;
	}

	bool repeatedSubstringPattern2(string s) {
		int* next = new int[s.size()];
		getNext1(next, s);
		if (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0)return true;
		return false;
	}
	void getNext1(int* next, string s) {
		int j = 0;
		next[0] = j;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j])
				j = next[j - 1];
			if (s[i] == s[j])
				j++;
			next[i] = j;
		}
	}


};

void main() {
	Solution st;
	string s1("abab"), s2("aba");
	cout << boolalpha << st.repeatedSubstringPattern(s1) << endl;
	cout << st.repeatedSubstringPattern(s2) << noboolalpha << endl;
	cout << boolalpha << st.repeatedSubstringPattern2(s1) << endl;
	cout << st.repeatedSubstringPattern2(s2) << noboolalpha << endl;
}