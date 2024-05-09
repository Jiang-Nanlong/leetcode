#include <iostream>
#include <vector>
using namespace std;

//这个题是给定一个数组，然后从数组中选出最大值作为根节点，然后最大值左边的数就位于左子树上，最大值右边的数位于右子树上。
//还是跟LeetCode 105 106 一样做

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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return Helper(nums, 0, nums.size());
	}

	TreeNode* Helper(vector<int>& nums, int left, int right) {
		if (left == right) return nullptr;

		int maxvalueindex = left;
		for (int i = left; i < right; i++) {
			if (nums[maxvalueindex] < nums[i]) {
				maxvalueindex = i;
			}
		}

		TreeNode* root = new TreeNode(nums[maxvalueindex]);
		int leftBegin = left;
		int leftEnd = maxvalueindex;
		int rightBegin = maxvalueindex + 1;
		int rightEnd = right;

		root->left = Helper(nums, leftBegin, leftEnd);
		root->right = Helper(nums, rightBegin, rightEnd);

		return root;
	}


	//第二次做
	TreeNode* constructMaximumBinaryTree1(vector<int>& nums) {
		return constructMaximumBinaryTreeHelper(nums, 0, nums.size());
	}

	TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int begin, int end) {
		if (end == begin) return nullptr;

		int maxValueIndex = begin;
		for (int i = begin; i < end; i++) {
			if (nums[i] > nums[maxValueIndex])
				maxValueIndex = i;
		}

		TreeNode* root = new TreeNode(nums[maxValueIndex]);
		root->left = constructMaximumBinaryTreeHelper(nums, begin, maxValueIndex);
		root->right = constructMaximumBinaryTreeHelper(nums, maxValueIndex + 1, end);
		return root;
	}
};

void main() {}
