#include <iostream>
#include <queue>
using namespace std;

//��ĿҪ����ÿ���ڵ㶼��һ��nextָ�룬Ҫ��ÿһ���nextָ�붼��������ָ�������Ҳ�ڵ㡣��ʼ״̬�£�ÿ���ڵ��nextָ�붼��nullptr
//������LeetCode 116 ��ȫһ��

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


	//�ڶ�����
	Node* connect(Node* root) {
		if (root == nullptr) return root;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			while (size--) {  //һ��ʼ�Ұ�����д��while(size-->1)�ˣ�����һֱ����ʱ�Ĵ��󣬿�ʼ���벻����ֻ���ſ�ʼÿ���ڵ��nextָ�붼�Ѿ���ʼ��Ϊnull�ˣ�
				//���ø����һ���ڵ�Ūnextָ������ˡ������������д��size-->1�Ļ����Ͳ��������ÿһ�е����һ����Ҳ�Ͳ���������������ӽڵ���ڶ��У����Գ�ʱ�ˡ�
				Node* cur = que.front();
				que.pop();
				if (size) cur->next = que.front();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return root;
	}
};

void main() {}