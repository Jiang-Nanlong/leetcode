#include <iostream>
#include <vector>
using namespace std;

//�����о��е��ѡ�Ҫ���ҳ������������������ȡ���ʼ����Ƕ�����ֻ֧�ִ��������ң���ô�ܴ��������ء�
//�������˴�������¼����Ƶ����֪������������Դ������ϡ�
//�о���������¼�����˼·��һ�����벻����
//������������һ��˼·������ͨ��ǰ��������ҵ����ڵ㵽ָ���ڵ��·����Ȼ��ֱ��ҳ���p��q��·����Ȼ��Ƚ�����·���������ҳ�����Ĺ����ڵ㡣

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;
		if (root == p || root == q) return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right) return root;
		else if (left && right == nullptr) return left;
		else if (left == nullptr && right) return right;
		else return nullptr;
	}


	//�����flag��������ʾ�Ƿ��ҵ���ָ���ڵ㣬����ҵ��˾Ͳ��õ���path��ĩβ�ڵ㡣
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pathP, pathQ;
		bool flag = false;
		pretraversal(root, p, pathP, flag);
		flag = false;
		pretraversal(root, q, pathQ, flag);
		for (int i = 0, j = 0; i < pathP.size() && j < pathQ.size(); i++, j++) {
			if (pathP[i] != pathQ[j]) return pathP[i - 1];
		}
		if (pathP.size() < pathQ.size()) return pathP.back();
		else return pathQ.back();
	}

	void pretraversal(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& flag) {
		if (flag) return;
		if (root == nullptr) return;

		path.push_back(root);
		if (root == target) {
			flag = true;
			return;
		}

		pretraversal(root->left, target, path, flag);
		pretraversal(root->right, target, path, flag);
		if (flag) return;
		path.pop_back();       //����ط���pop��LeetCode 257 ������������·���е�pop��̫һ������һֱŪ���壬�����ֶ�����һ�²�֪����257����⵽Ҷ�ڵ�ͽ����ˣ�return�ˣ�Ȼ����Ҷ�ڵ����һ�㵯��Ҷ�ڵ㡣
		//�������ǿ��Ե�Ҷ�ڵ����һ�㣬Ȼ����һ��Ϊ�վ�return��Ȼ����Ҷ�ڵ㱾��Ϳ��Ե���Ҷ�ڵ㡣���ԣ�257��Ҫ�ֿ�pop�����������һ��pop��
	}

	//�ڶ�����������û��������ֻ�뵽���ú������������ûд������
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		if (root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor2(root->left, p, q);
		TreeNode* right = lowestCommonAncestor2(root->right, p, q);

		if (left && right)
			return root;
		else if (left == NULL && right)
			return right;
		else if (left && right == NULL)
			return left;
		else
			return NULL;
	}

	//�ֿ���һ�µ�һ������ʱ���õ�ǰ������ķ��������������ͦ��
};

void main() {}