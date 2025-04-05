//
// Created by cml on 25-4-5.
//
#include <iostream>
#include <functional>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (!cur)
                return 0;

            int leftval = max(0, dfs(cur->left));
            int rightval = max(0, dfs(cur->right));
            res = max(res, cur->val + leftval + rightval);
            return cur->val + max(leftval, rightval);
        };
        dfs(root);
        return res;
    }
};
int main() {

}