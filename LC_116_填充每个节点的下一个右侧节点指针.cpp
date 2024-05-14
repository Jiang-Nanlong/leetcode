#include <iostream>
#include <queue>
using namespace std;

//��ĿҪ����ÿ���ڵ㶼��һ��nextָ�룬Ҫ��ÿһ���nextָ�붼��������ָ�������Ҳ�ڵ㡣��ʼ״̬�£�ÿ���ڵ��nextָ�붼��nullptr

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


	//�ڶ���������������о���һ��д��̫�����ˡ�
	Node* connect1(Node* root) {
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

	// ��������
	Node* connect2(Node* root) {
		if (root == NULL)
			return NULL;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			Node* cur = NULL;
			while (size-- > 1) {
				cur = que.front();
				que.pop();
				cur->next = que.front();
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			cur = que.front();
			que.pop();
			cur->next = NULL;
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
		return root;
	}

	//���Ժ�
	Node* connect3(Node* root) {
		if (root == NULL)
			return NULL;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			Node* cur = NULL;
			while (size--) {
				cur = que.front();
				que.pop();
				if (size) {
					cur->next = que.front();
				}
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
		}
		return root;
	}
};

void main() {

}