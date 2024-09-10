#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ������Ϊn��������start����һ������d���������n������[start[i], start[i]+d]
// �÷ֵĶ���Ϊ��ѡ��������֮�����С���Բ��Ҫ��n��������ѡ��n��������ÿ������һ����
// ������ѡ�����÷ֵ����ֵ��

// ���Ƕ���

// �÷�����ѡ��������֮�����С���Բ��ôΪ����������Բ���ܵĴ�Ҫ����n������֮��ֲ������ܵľ��ȡ�
// ��������ö��n������֮�����С���Բ
// ��ô�ж�һ�����Բ��Ƿ�����أ� ��ĿҪ����Ҫ��n�������У�ÿ������ѡһ�����������һ������ѡ��һ����x����x����С���Բ�len�ϻ�������һ��Ӧ��ѡ����Ӧ����x+len��
// ���x+len�����˵ڶ�����������ֵ����ô��û���ڵڶ�������ȡ�ڶ������ˣ���ô�����С���Բ�len���ǲ����ʵġ�

class Solution {
public:
	int maxPossibleScore(vector<int>& start, int d) {
		sort(start.begin(), start.end());

		auto check = [&](long long len) {
			long long x = start[0];
			for (int i = 1; i < start.size(); i++) {
				x = max(x + len, 1LL * start[i]);  // ��Ϊlen�������n����������֮�����С���ԲҲ����ζ����һ�����д���һ��������������ǵľ��Բ����len
				// ���ԣ������1������ѡ����x������С���Բ�len�Ļ����ϣ��ڶ�������Ӧ��ѡ��x+len������x+lenС�ڵڶ����������Сֵ����ô��ʱ�����ڵڶ�������Ҫȡֵ�Ļ�
				// ֻ��ѡ��ڶ����������˵��ˡ�
				if (x > start[i] + d)
					return false;
			}
			return true;
		};

		long long left = 0, right = (start.back() + d - start[0]) / (start.size() - 1) + 1;
		while (left < right) {  // ��������Ķ�����ֹ��������д���ã����ǻ�������ѭ��
			long long mid = ((right + left + 1) >> 1);
			if (check(mid))
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};

int main() {
	Solution st;
	vector<int> start{ 6,0,3 };
	int d = 2;
	cout << st.maxPossibleScore(start, d) << endl;
	return 0;
}