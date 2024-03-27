#include <iostream>
#include <queue>
using namespace std;

//还是层序遍历

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


	//第二次做
	int maxDepth(Node* root) { return getMaxDepth(root); }

	int getMaxDepth(Node* root) {
		if (root == nullptr)
			return 0;
		int maxdepth = 0;  //一开始的时候这里写成INT_MIN，但是结果都是错的，不知道为啥，按说应该没问题啊
		for (auto& p : root->children) {
			maxdepth = max(maxdepth, getMaxDepth(p));
		}
		return 1 + maxdepth;
	}
};

void main() {}