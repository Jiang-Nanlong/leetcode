#include <iostream>
#include <vector>
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
	vector<int> postorder(Node* root) {
		vector<int> res;
		postorderHelper(res, root);
		return res;
	}
	void postorderHelper(vector<int>& res, Node* root) {
		if (root == nullptr) return;
		for (auto& p : root->children)
			postorderHelper(res, p);
		res.push_back(root->val);
	}
};

void main() {}
