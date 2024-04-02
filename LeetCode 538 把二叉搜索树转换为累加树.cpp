#include <iostream>
using namespace std;

//�������Ҫ��ÿ���ڵ��ֵ��Ϊ���ڻ���ڸý���ֵ�����нڵ�ֵ�ĺ͡�
//��Ϊ���Ƕ�������������Ȼ�����������½ǣ����Դ��ڵ��ڸý��ֵ�Ľ�㶼�����ұߣ�����ֻҪ�����������˳����С����������������������

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int pre = 0;
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) return nullptr;
		convertBST(root->right);
		root->val += pre;
		pre = root->val;
		convertBST(root->left);

		return root;
	}

	//�ڶ�����
    int sum = 0;
    TreeNode* convertBST1(TreeNode* root) {
        //�ȱ���һ�����������ýڵ�ֵ�ĺͣ�����������������sum�ݼ�ǰһ���ڵ��ֵ
        //����Ҳ������һ��ֵ����ǰһ���ڵ��ֵ��Ȼ���ڵ�ǰ������м�ȥǰһ���ڵ��ֵ

        if (root == nullptr) return nullptr;

        sum = getSum(root);
        cout << sum;
        convertBSTHelper(root);
        return root;
    }

    int getSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftSum = getSum(root->left);
        int rightSum = getSum(root->right);
        return root->val + leftSum + rightSum;
    }

    void convertBSTHelper(TreeNode* root) {
        if (root == nullptr) return;
        convertBSTHelper(root->left);
        int value = root->val;
        root->val = sum;
        sum -= value;
        convertBSTHelper(root->right);
    }

    //���˴𰸲ŷ��ֿ�����������ı���˳��sum��ʾ��ǰ�ڵ��ǰһ���ڵ��ֵ��Ҳ���ǵ�ǰ�ڵ��ұߵ����нڵ�ֵ�ĺ�
    int sum = 0;
    TreeNode* convertBST2(TreeNode* root) {
        if (root == nullptr) return nullptr;
        convertBST2(root->right);
        root->val += sum;
        sum = root->val;
        convertBST2(root->left);
        return root;
    }
};

void main() {}