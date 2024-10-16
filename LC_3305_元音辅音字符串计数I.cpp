#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int countOfSubstrings(string word, int k) {
		unordered_map<char, int> umap1, umap2;
		int res = 0;
		for (int i1 = 0, i2 = 0, j = 0; j < word.size(); j++) {
			char c = word[j];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				umap1[c]++;
				umap2[c]++;
			}
			while (umap1.size() == 5 && (j - i1 + 1 - getCount(umap1) > k)) {
				c = word[i1];
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
					if (--umap1[c] == 0)
						umap1.erase(c);
				}
				i1++;
			}

			while (umap2.size() == 5 && (j - i2 + 1 - getCount(umap2) >= k)) {
				c = word[i2];
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
					if (--umap2[c] == 0)
						umap2.erase(c);
				}
				i2++;
			}
			res += i2 - i1;
		}
		return res;
	}

private:
	int getCount(const unordered_map<char, int>& umap) {
		int sum = 0;
		for (auto it = umap.begin(); it != umap.end(); it++)
			sum += it->second;
		return sum;
	}
};

int main() {
	Solution st;
	string word("ieaouqqieaouqq");
	int k = 1;
	cout << st.countOfSubstrings(word, k) << endl;
	return 0;
}