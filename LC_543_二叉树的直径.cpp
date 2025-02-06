//
// Created by ≤‹√œ¡˙ on 25-2-6.
//

#include <functional>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
            if (node == nullptr)
                return 0;
            int left = dfs(node->left) + 1;
            int right = dfs(node->right) + 1;
            res = max(res, left + right);
            return max(left, right);
        };
        dfs(root);
        return res - 2;
    }
};

int main() {
    return 0;
}
