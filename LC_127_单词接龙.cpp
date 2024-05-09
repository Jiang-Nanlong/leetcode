#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//����һ��wordList�����һЩ���ʣ�Ȼ��һ��beginword��һ��endword�����еĵ��ʳ��ȶ�һ����beginword����wordlist�У�endword��wordlist�У�������̱任�����еĳ��ȣ�����beginword���endword��ÿ��ֻ�ܱ任һ����ĸ��
//�����еĵ��ʶ��Ǵ�wordlist���ҡ�������������������У��ͷ���0��
//���ڵ������任֮��ֻ��һ����ĸ��������������ȱ���������������ô��ʾ�������ݽṹ�أ���ֻ��һ����ĸ�ĵ��ʿ����໥�任��
// 
//���˽����֪������˵��������ͼ�����·���������õ���bfs������������·������Ϊֻ��bfs�ܱ������յ㣬��ô������ľ������·�������Ҵ���㵽�յ��·����ֹһ��
//����ѣ��벻�������ǿ��������ܿ�����

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> uset(wordList.begin(), wordList.end());  //vectorת����unordered_set���������Ҹ���
		if (uset.find(endWord) == uset.end()) return 0;  //����յ㲻��wordlist�ֱ�ӷ���0

		unordered_map<string, int> visitMap;  //������¼wordlist�е�ĳ�����Ƿ��Ѿ������������Ҵ���㵽�����ľ����Ƕ���
		queue<string> que;
		que.push(beginWord);
		visitMap.insert(pair<string, int>(beginWord, 1));
		while (!que.empty()) {
			string word = que.front();
			que.pop();
			int path = visitMap[word];
			for (int i = 0; i < word.size(); i++) {  //û�뵽������forѭ������ѡ��һ�����Ա������ĵ��ʵķ�������Ȼ������ô��ʵ�޻�
				string newword = word;
				for (int j = 0; j < 26; j++) {
					newword[i] = j + 'a';
					if (newword == endWord) return path + 1;  //�����һ���ڵ����ֱ�ӱ������յ㣬ֱ�ӷ���path+1
					if (uset.find(newword) != uset.end() && visitMap.find(newword) == visitMap.end()) {   //�����ǰ�ڵ�û�б�����������������wordlist�У��Ͱ�����ӵ�visitMap��que��
						visitMap.insert(pair<string, int>(newword, path + 1));
						que.push(newword);
					}
				}
			}
		}
		return 0;
	}

	//�ڶ������������벻����ô��
	// ���Ŵ�д���Ժ󣬷���һ������⣬�о���������ʵ���������л�ͼ������֮������·����
	// �ѵ�������ô�ж�������֮���Ƿ������ӣ���������һ�ֱ���������Ϊ�����������֮�������ӵĻ���˵����������ֻ��һ����ĸ�����Դ��а������������е���ĸ��Ȼ���������������ĸ���ж��Ƿ���һ��ʼ��wordlist�У�
	// �پ��Ǳ���ʹ�ù������������������������һ���½��ʱ����Ҫ��·������������㵽������½������·��
	int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> uset(wordList.begin(), wordList.end());
		if (uset.find(endWord) == uset.end())
			return 0;

		queue<string> que;
		que.push(beginWord);
		unordered_map<string, int> umap;   //������㵽ÿ�����ʵ�·������
		umap.insert(make_pair(beginWord, 1));

		while (!que.empty()) {
			string word = que.front();
			que.pop();
			int pathlength = umap[word];

			for (int i = 0; i < word.size(); i++) {  //���������е�ÿһ����ĸ
				string newword = word;
				for (int j = 0; j < 26; j++) {		//��������ÿһ����ĸ
					newword[i] = j + 'a';
					if (newword == endWord)     //���������endword
						return pathlength + 1;

					if (uset.find(newword) != uset.end() && umap.find(newword) == umap.end()) {  //�����ǰ������wordlist�У����һ�û����㵽��ǰ���ʵ����·������
						umap.insert(make_pair(newword, pathlength + 1));
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
	cout << st.ladderLength1(beginWord, endWord, wordList) << endl;
	return 0;
}