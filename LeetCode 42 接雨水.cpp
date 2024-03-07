#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> res(height.size(), -1);
		stack<int> stk;
		for (int i = 0; i < height.size(); i++) {
			while (!stk.empty() && height[i] >= height[stk.top()]) {
				res[stk.top()] = height[i];
				stk.pop();
			}
			stk.push(i);
		}
		int j = 0, count = 0;

		for (int i = 1; i < res.size(); i++) {
			if (height[i] < height[j] && res[j] != -1) {
				count = count + height[j] - height[i];
			}
			else {
				j = i;
			}
		}
		return count;
	}
	//���������Լ�д�Ĵ��룬���������ÿһ��λ���ұߵĵ�һ�����Ԫ�أ�Ȼ�����ô������ұ������е�֮ǰ����������������ĸо��ˣ������������Ļ�������[4,2,3]���־�����

	//�±��Ǵ�������¼�ĳ��������Ǻ�����ģ�Ҳ��������׺͸ߣ�Ȼ�������
	int trap1(vector<int>& height) {
		vector<int> res(height.size(), -1);
		stack<int> stk;
		int count = 0;
		for (int i = 0; i < height.size(); i++) {
			while (!stk.empty() && height[i] > height[stk.top()]) {
				int mid = height[stk.top()];
				stk.pop();
				if (!stk.empty()) {
					int h = min(height[i], height[stk.top()]) - mid;
					int w = i - stk.top() - 1;
					count = count + h * w;
				}
			}
			stk.push(i);
		}
		return count;
	}
};

int main() {
	Solution st;
	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << st.trap(height) << endl;
	cout << st.trap1(height) << endl;
	return 0;
}