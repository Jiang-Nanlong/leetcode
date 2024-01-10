#include <iostream>
#include <queue>
using namespace std;

//ªπ «≤„–Ú±È¿˙

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		if (root == nullptr) return 0;
		queue<Node*> que;
		que.push(root);
		int count = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				Node* cur = que.front();
				que.pop();
				for (auto& p : cur->children)
					que.push(p);
			}
			count++;
		}
		return count;
	}
};

void main() {}