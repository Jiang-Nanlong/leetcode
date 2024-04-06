#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//给定一个nums数组，和一个窗口大小为k的滑动窗口，然后每次窗口右移一个，每次返回窗口内的最大值
//这是一个困难题，刚开始看一点头绪没有。然后就看了代码随想录的视频。
//这里用队里来表示窗口，返回窗口内的最大值，但是没有这样的数据结构，所以自己写了一个MyQueue。这是一个递减队列，队列中的最大值就表示当前窗口的最大值。
//这个数据结构使用双端队列，然后有三个操作，一个是pop，一个push，一个getMax。
//pop这个容易想，就是如果滑出窗口的那个值等于队列当前的最大值，那么就出队
//push比较难想，因为队列一直维护递减，然后队列中的最大值就是窗口内的最大值。然后这个push比较有意思，用刚进入窗口的值与队列从后向前比，因为是双端队列，可以在后边出队，如果队列中的值小于刚进入窗口的值，就出队，然后继续往前比，知道没有比当前值大的，
//然后当前值入队。其实到这里也比较好想，因为那些比当前值小的数，不可能是窗口内的最大值了，直接出队就行了。然后当前值并不一定是窗口内的最大值，他可能是下一个窗口的最大值，所以要入队。
//getMax直接返回对头元素就行了

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

//第二遍再做这个题还是不会，还是看的答案才知道怎么做，但是又想不明白为什么这么做。
//只把可能成为最大值的数加进去，

int main() {
	Solution st;
	vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	vector<int> res = st.maxSlidingWindow(nums, k);
	for (auto& i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}
