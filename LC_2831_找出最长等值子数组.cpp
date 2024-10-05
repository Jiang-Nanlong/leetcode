#include <iostream>
#include <vector>
using namespace std;

// ����һ�����������һ���Ǹ�����k��k��ʾ�������Ƴ���Ԫ�صĸ�����
// ����������е�Ԫ�ض���һ���ģ���ô��˵�����������һ����ֵ�����飬������Ҳ�ǵ�ֵ�����顣
// ������ĵ�ֵ������ĸ�����

class Solution {
public:
    // û�����������Ĵ�������¼��˼·
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> vec(n + 1);  //vec[i]��ʾ����ֵΪi��Ԫ�ص��±�ļ���
        for (int i = 0; i < n; i++)
            vec[nums[i]].push_back(i);

        int maxlen = 0;
        for (auto& v : vec) {
            // ����һ��vec[k]�����е�vec[k][i]��vec[k][j]��ʾ����������Ҷ˵㣬����vec[k][j]-vec[k][i]+1��Ԫ��
            // i��j��ʾ�������е�ֵԪ�ص����Ҷ˵㣬�����������й���j-i+1����ֵԪ��
            // ���vec[k][j]-vec[k][i] - (j-i) > k�Ļ���˵����ǰ�����鴰�����ж���k��Ԫ����Ҫɾ�������Դ�ʱҪ��С����
            for (int i = 0, j = 0; j < v.size(); j++) {
                while (v[j] - v[i] - (j - i) > k) {
                    i++;
                }
                maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,2,3,1,3 };
    int k = 3;
    cout << st.longestEqualSubarray(nums, k) << endl;
    return 0;
}