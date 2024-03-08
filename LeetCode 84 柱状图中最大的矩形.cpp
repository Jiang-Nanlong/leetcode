#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//����״ͼ�����ľ�������������ͽ���ˮ���������෴������ˮ��������height[i]������ߵ����ӣ������Ҫ����С�ġ��������ҳ��������ߵ�һ����С�����ӣ���������С�����м�Χ�����ľ�����height[i]Ϊ�ߵľ���


class Solution {
public:

	int largestRectangleArea(vector<int>& heights) {
		vector<int> minLeftIndex(heights.size());
		vector<int> minRightIndex(heights.size());
		int size = heights.size();

		minLeftIndex[0] = -1;
		for (int i = 1; i < size; i++) {
			int t = i - 1;
			//while (t >= 0 && heights[t] >= heights[i]) t--;  //��ôд�Ļ��ᳬʱ����Ϊt��һ��һ���ƶ���
			while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];   //�����Ļ�t��������֮ǰ�Ľ�������ƶ�
			minLeftIndex[i] = t;
		}

		minRightIndex[size - 1] = size;
		//for (int i = 0; i < size - 1; i++) {  //ͬ����ôдҲ�ᳬʱ
		//	int t = i + 1;
		//	while (t < size && heights[t] >= heights[i]) t++;
		//	//while (t < size && heights[t] >= heights[i]) t = minRightIndex[t]; //����ĳ������Ļ����ͻ�������ѭ������Ϊ�����ʼ��ʼ��minRightIndex�ǳ�ʼ�������һ�������������forѭ��Ӧ�õ������
		//	minRightIndex[i] = t;
		//}

		for (int i = size - 2; i >= 0; i--) {
			int t = i + 1;
			while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
			minRightIndex[i] = t;
		}

		int res = 0;
		for (int i = 0; i < size; i++) {
			int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
			res = max(sum, res);
		}
		return res;
	}

	//����ջ����������ǵ�һ����heights[i]С��Ԫ��
	int largestRectangleArea1(vector<int>& heights) {
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		//�����бȽ���Ҫ���ڽ���ˮ���Ǹ�����û������������Ϊ�Ǹ����ﲻ�ÿ������˵����ӣ����ﲻһ��������Ҫ�������˵�
		//���û������0����ô����{2,4,6,8}����������ʱ���ͼ��㲻���������Ϊÿһ����height[i]���Ǵ���heights[stk.top()]�ģ�
		//ͬ�����û�е�һ��0����ô����{8,6,4,2}����������ʱ�����ջ�ھͻ�ֻʣһ��8����ʱ��ͼ��㲻����һ�����εĽ����
		stack<int> stk;
		int sum = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (!stk.empty() && heights[i] < heights[stk.top()]) {
				int h = heights[stk.top()];
				stk.pop();
				if (!stk.empty()) {  //��Ϊ������ͷ��������0����������ж�������ʡ�ԣ���Ϊ�����������һ��0��ʱ��ջ��Ҳֻ����һ��0������Ϊwhileѭ�����ж�������heights[i] < heights[stk.top()]
					//������ʱ������������ѭ������������Ҳ�������ˣ���ֱ���˳��ˡ�
					int w = i - stk.top() - 1;
					sum = max(sum, h * w);
				}
			}
			stk.push(i);
		}
		return sum;
	}
};

int main() {
	Solution st;
	vector<int> heights = { 2, 1, 5, 6, 2, 3 };
	cout << st.largestRectangleArea(heights) << endl;
	cout << st.largestRectangleArea1(heights) << endl;
	return 0;
}