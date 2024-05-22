#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//����һ��nums���飬��һ�����ڴ�СΪk�Ļ������ڣ�Ȼ��ÿ�δ�������һ����ÿ�η��ش����ڵ����ֵ
//����һ�������⣬�տ�ʼ��һ��ͷ��û�С�Ȼ��Ϳ��˴�������¼����Ƶ��
//�����ö�������ʾ���ڣ����ش����ڵ����ֵ������û�����������ݽṹ�������Լ�д��һ��MyQueue������һ���ݼ����У������е����ֵ�ͱ�ʾ��ǰ���ڵ����ֵ��
//������ݽṹʹ��˫�˶��У�Ȼ��������������һ����pop��һ��push��һ��getMax��
//pop��������룬��������������ڵ��Ǹ�ֵ���ڶ��е�ǰ�����ֵ����ô�ͳ���
//push�Ƚ����룬��Ϊ����һֱά���ݼ���Ȼ������е����ֵ���Ǵ����ڵ����ֵ��Ȼ�����push�Ƚ�����˼���øս��봰�ڵ�ֵ����дӺ���ǰ�ȣ���Ϊ��˫�˶��У������ں�߳��ӣ���������е�ֵС�ڸս��봰�ڵ�ֵ���ͳ��ӣ�Ȼ�������ǰ�ȣ�֪��û�бȵ�ǰֵ��ģ�
//Ȼ��ǰֵ��ӡ���ʵ������Ҳ�ȽϺ��룬��Ϊ��Щ�ȵ�ǰֵС�������������Ǵ����ڵ����ֵ�ˣ�ֱ�ӳ��Ӿ����ˡ�Ȼ��ǰֵ����һ���Ǵ����ڵ����ֵ������������һ�����ڵ����ֵ������Ҫ��ӡ�
//getMaxֱ�ӷ��ض�ͷԪ�ؾ�����

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MyQueue que;
		vector<int> res;
		for (int i = 0; i < k; i++) {
			que.push(nums[i]);
		}
		res.push_back(que.getMax());
		for (int i = k; i < nums.size(); i++) {
			que.pop(nums[i - k]);
			que.push(nums[i]);
			res.push_back(que.getMax());
		}
		return res;
	}
private:
	class MyQueue {
	public:
		deque<int> que;

		void pop(int x) {
			if (!que.empty() && x == que.front())
				que.pop_front();
		}
		void push(int x) {
			while (!que.empty() && que.back() < x)
				que.pop_back();
			que.push_back(x);
		}
		int getMax() {
			return que.front();
		}
	};
};


//�ڶ�����������⻹�ǲ��ᣬ���ǿ��Ĵ𰸲�֪����ô�����������벻����Ϊʲô��ô����
//ֻ�ѿ��ܳ�Ϊ���ֵ�����ӽ�ȥ��


// ���������ˣ�����û������
class Solution1 {
private:
	class MyQue {
		deque<int> que;

	public:
		void pop(int value) {
			if (!que.empty() && que.front() == value)
				que.pop_front();
		}

		void push(int value) {
			while (!que.empty() && que.back() < value)
				que.pop_back();
			que.push_back(value);
		}

		int front() { return que.front(); }
	};

public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MyQue que;
		vector<int> res;
		for (int i = 0; i < k && i < nums.size(); i++)
			que.push(nums[i]);

		res.push_back(que.front());
		for (int i = k; i < nums.size(); i++) {
			que.pop(nums[i - k]);
			que.push(nums[i]);
			res.push_back(que.front());
		}
		return res;
	}
};
int main() {
	Solution st;
	vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	vector<int> res = st.maxSlidingWindow(nums, k);
	for (auto& i : res)
		cout << i << " ";
	cout << endl;

	Solution1 st1;
	vector<int> res1 = st1.maxSlidingWindow(nums, k);
	for (auto& i : res1)
		cout << i << " ";
	cout << endl;
	return 0;
}