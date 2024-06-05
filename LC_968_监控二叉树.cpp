#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//�����е�ĳ���ڵ����һ������ͷ�����Լ�ص�ǰ�ڵ�ĸ��ڵ�����Һ��ӽڵ��Լ��������ܹ����㣬��������Ҫ���ٸ�����ͷ���Ը���������
//�����̰��̰��������ͷҪ�����������ηţ���Ϊ����������·ŵĻ������ܻ���õ�Ҷ�ӽ���ϣ�Ҷ�ӽ�����һ��Ϊ�գ��ͻ��˷ѵ�һ�㸲�Ƿ�Χ��Ҳ���൱���˷�������ͷ�Ĺ���
//�����ٿ���������Ҳ���Ǻ��ѡ�
//���ú����������Ȼ�ģ����������ں����������ô�����м�ڵ�����⡣
//�м�ڵ��Ƿ�Ӧ�÷�������ͷ���Ը������Һ������ƶϡ�
//����һ��������״̬�� 0.��ʾ��ǰ�ڵ��޸��ǣ�1.��ʾ��ǰ�ڵ������  2.��ʾ��ǰ�ڵ��и���
//Ҷ�ӽڵ�ĺ��ӽڵ��״̬һ����2 �и��ǵģ������0�Ļ���Ҷ�ӽ��͵÷�������ͷ�������1�Ļ���Ҷ�ӽ���Ӧ���Ѿ������ǣ�ֻ����Ҷ�ӽ���үү�ڵ������ͷ
//������ֹ�������� if (cur == nullptr) return 2;
//Ȼ��������Һ��ӵ�״̬����ǰ�ڵ��״̬�ֿ��Է�Ϊ���֣�
//1. ���Һ��Ӷ��и����ˣ�����ͷ���Ǵ������ϰ�װ�ģ����Ե�ǰ�ڵ�϶����޸��ǵģ�Ҳ����0��
//2. �����Һ����޸��ǣ� ������������ͷ���Һ����޸��ǣ�����ڵ��޸��ǣ��Һ���������ͷ��
//   �������޸��ǣ��ҽڵ��и��ǣ������Ӹ��ǣ��Һ����޸��ǡ� ���������˵����ǰ�ڵ㶼Ӧ�÷���һ������ͷ
//3. ������������ͷ���Һ����и��ǣ��������и��ǣ��Һ���������ͷ�������Һ��Ӷ�������ͷ������������£���ǰ�ڵ㶼�Ǳ������˵ġ�

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
        if (traversal(root) == 0)  //���Ӧ���жϸ��ڵ��״̬��������ڵ��޸��ǣ���Ӧ�÷���һ������ͷ
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

    // ��������������ֹ����д���ˣ��پ��ǰ� 2 2�����д���ˣ�д��1�ˡ�
    // ���Ƿ����������0��ʾ�޸��ǣ�1��ʾ��װ����ͷ��2��ʾ�и���
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
        if (left == 0 || right == 0) {  // ��������������һ���޸��ǣ�00,01,02,10,20
            count++;
            return 1;
        }
        else if (left == 1 || right == 1) {  // ��������������һ������ͷ��11,12,21
            return 2;
        }
        else {  // �������������и��ǣ�22
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