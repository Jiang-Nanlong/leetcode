#include <iostream>
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
};

int main() {
    return 0;
}