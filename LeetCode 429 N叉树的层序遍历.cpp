#include <iostream>
#include <vector>
#include <queue>
using namespace std;


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
	vector<vector<int>> levelOrder(Node* root) {   //其实就是跟二叉树的层序遍历一样
		vector<vector<int>> res;
		if (root == nullptr) return res;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				Node* cur = que.front();
				que.pop();
				vec.push_back(cur->val);
				for (Node*& c : cur->children)
					que.push(c);
			}
			res.push_back(vec);
		}
		return res;
	}
};

void main() {}