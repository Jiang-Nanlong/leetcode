#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//在树中的某个节点放置一个摄像头，可以监控当前节点的父节点和左右孩子节点以及它本身，总共三层，问最少需要多少个摄像头可以覆盖整棵树
//这里的贪心贪的是摄像头要从下往上依次放，因为如果从上往下放的话，可能会放置到叶子结点上，叶子结点的下一层为空，就会浪费掉一层覆盖范围，也就相当于浪费了摄像头的功能
//现在再看这个题好像也不是很难。
//采用后序遍历是显然的，不过就是在后序过程中怎么处理中间节点的问题。
//中间节点是否应该放置摄像头可以根据左右孩子来推断。
//这里一共有三种状态， 0.表示当前节点无覆盖；1.表示当前节点有相机  2.表示当前节点有覆盖
//叶子节点的孩子节点的状态一定是2 有覆盖的，如果是0的话，叶子结点就得放置摄像头，如果是1的话，叶子结点就应该已经被覆盖，只能在叶子结点的爷爷节点放摄像头
//所以终止条件就是 if (cur == nullptr) return 2;
//然后根据左右孩子的状态，当前节点的状态又可以分为几种：
//1. 左右孩子都有覆盖了，摄像头又是从下往上安装的，所以当前节点肯定是无覆盖的，也就是0；
//2. ①左右孩子无覆盖； ②左孩子有摄像头，右孩子无覆盖；③左节点无覆盖，右孩子有摄像头；
//   ④左孩子无覆盖，右节点有覆盖；⑤左孩子覆盖，右孩子无覆盖。 这五种情况说明当前节点都应该放置一个摄像头
//3. ①左孩子有摄像头，右孩子有覆盖；②左孩子有覆盖，右孩子有摄像头；③左右孩子都有摄像头。这三种情况下，当前节点都是被覆盖了的。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int result;
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0)  //最后还应该判断根节点的状态，如果根节点无覆盖，还应该放置一个摄像头
            result++;
        return result;
    }

    int traversal(TreeNode* cur) {
        if (cur == nullptr) return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        if (left == 2 && right == 2) return 0;

        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        if (left == 1 || right == 1) return 2;
        return -1;
    }

    // 第三次做，把终止条件写错了，再就是把 2 2的情况写错了，写成1了。
    // 还是分三种情况，0表示无覆盖，1表示安装摄像头，2表示有覆盖
    int count;
    int minCameraCover1(TreeNode* root) {
        count = 0;
        if (backtracking(root) == 0)
            return count + 1;
        return count;
    }
    int backtracking(TreeNode* root) {
        if (root == nullptr)
            return 2;

        int left = backtracking(root->left);
        int right = backtracking(root->right);
        if (left == 0 || right == 0) {  // 左右子树至少有一个无覆盖，00,01,02,10,20
            count++;
            return 1;
        }
        else if (left == 1 || right == 1) {  // 左右子树至少有一个摄像头，11,12,21
            return 2;
        }
        else {  // 左右子树都是有覆盖，22
            return 0;
        }
    }

    TreeNode* buildTree(vector<string>& nums) {
        if (nums.empty()) return nullptr;

        TreeNode* root = new TreeNode(stoi(nums[0]));
        queue<TreeNode*> que;
        que.push(root);

        int i = 1;
        while (i < nums.size()) {
            TreeNode* node = que.front();
            que.pop();

            if (nums[i] != "null") {
                node->left = new TreeNode(stoi(nums[i]));
                que.push(node->left);
            }
            i++;

            if (i < nums.size() && nums[i] != "null") {
                node->right = new TreeNode(stoi(nums[i]));
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    Solution st;
    vector<string> nums{ "0","0","null","0","0" };
    TreeNode* root = st.buildTree(nums);
    cout << st.minCameraCover1(root) << endl;
    return 0;
}