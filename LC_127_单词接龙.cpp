#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//给定一个wordList里边有一些单词，然后一个beginword，一个endword，所有的单词长度都一样。beginword不在wordlist中，endword在wordlist中，返回最短变换序列中的长度，来把beginword变成endword，每次只能变换一个字母，
//序列中的单词都是从wordlist中找。如果不存在这样的序列，就返回0。
//相邻的两个变换之间只差一个字母，可以用深度优先遍历来做，但是怎么表示这种数据结构呢？让只差一个字母的单词可以相互变换。
// 
//看了讲解才知道，这说的是无向图求最短路径，这里用的是bfs求的两点间的最短路径，因为只有bfs能遍历到终点，那么求出来的就是最短路径。而且从起点到终点的路径不止一条
//真的难，想不到，但是看代码又能看明白

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> uset(wordList.begin(), wordList.end());  //vector转换成unordered_set，后续查找更快
		if (uset.find(endWord) == uset.end()) return 0;  //如果终点不在wordlist里，直接返回0

		unordered_map<string, int> visitMap;  //用来记录wordlist中的某个点是否已经遍历过，而且从起点到这个点的距离是多少
		queue<string> que;
		que.push(beginWord);
		visitMap.insert(pair<string, int>(beginWord, 1));
		while (!que.empty()) {
			string word = que.front();
			que.pop();
			int path = visitMap[word];
			for (int i = 0; i < word.size(); i++) {  //没想到这两个for循环来挑选下一个可以遍历到的单词的方法，竟然可以这么朴实无华
				string newword = word;
				for (int j = 0; j < 26; j++) {
					newword[i] = j + 'a';
					if (newword == endWord) return path + 1;  //如果上一个节点可以直接遍历到终点，直接返回path+1
					if (uset.find(newword) != uset.end() && visitMap.find(newword) == visitMap.end()) {   //如果当前节点没有被遍历，而且他还在wordlist中，就把它添加到visitMap和que中
						visitMap.insert(pair<string, int>(newword, path + 1));
						que.push(newword);
					}
				}
			}
		}
		return 0;
	}
};
int main() {
	Solution st;
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
	cout << st.ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}
