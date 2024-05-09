#include<iostream>
#include<vector>
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
	vector<int> preorder(Node* root) {
		vector<int> res;
		preorderHelper(res, root);
		return res;
	}
private:
	void preorderHelper(vector<int>& res, Node* root) {  //Ö±½ÓµÝ¹é
		if (root == nullptr) return;
		res.push_back(root->val);
		for (auto& c : root->children) {
			preorderHelper(res, c);
		}
	}
};

void main() {}
