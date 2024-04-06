#include <iostream>
#include <queue>
using namespace std;

//题目要求是每个节点都有一个next指针，要把每一层的next指针都串起来，指向他的右侧节点。初始状态下，每个节点的next指针都是nullptr

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr) return nullptr;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			Node* preNode = nullptr, * node = nullptr;
			for (int i = 0; i < size; i++) {
				if (i == 0) {
					preNode = que.front();
					que.pop();
					node = preNode;
				}
				else {
					node = que.front();
					que.pop();
					preNode->next = node;
					preNode = node;
				}
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return root;
	}


	//第二次做，这回再做感觉第一次写的太啰嗦了。
	Node* connect(Node* root) {
		if (root == nullptr)
			return nullptr;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			while (size-- > 1) {
				Node* cur = que.front();
				que.pop();
				if (size != 0)
					cur->next = que.front();
				else
					cur->next = nullptr;
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
		}
		return root;
	}

};

void main() {}
