#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�����Ҫ���������Ƴ����ٸ����䣬����ʹ��ʣ������䲻�ص�����ʵ����Ҫͳ���ж����ص������䡣
//��������ģ��LeetCode 452 ���ټ����䱬���������д���Ǹ����������ص����� �������ü�1������������෴�������ص����䣬count��++
//��ʵ�����԰�����ĳ����հ������ֻ��Ҫ������return����Ϊreturn intervals.size()-count���У������count�Ǽ���������

class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int count = 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int minrightmrigin = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] >= minrightmrigin)
				minrightmrigin = intervals[i][1];
			else {
				minrightmrigin = min(minrightmrigin, intervals[i][1]);
				count++;
			}
		}
		return count;
	}
};

int main() {
	Solution st;
	vector<vector<int>> intervals{ {1,2} ,{2,3},{3,4},{1,3} };
	int count = st.eraseOverlapIntervals(intervals);
	cout << count << endl;
	return 0;
}

//������֮ǰд�Ĵ���

/*
����һ������ļ��ϣ�������Ҫ�Ƴ��������С��������ʣ������以���ص�
*/
//����������������������һ��˼·��û�У���
//�����������ˣ��꣬����������˵��
//���쿴����⣬������˼����˵��������ұ߽������߽������԰��ұ߽�����Ϊ�����ұ߽��С��������Ȼ���ڴ����������α�����
//����С���ұ߽�����俪ʼ��ÿ�μ�¼��ǰ������ұ߽磬Ȼ���������Ϊ��׼�������������������ص����������߽磬���ν��У�����¼һ�����ٸ��ص�������
/*
class Solution {
public:
	static int cmp(vector<int>& x, vector<int>& y) {   //���ұ߽��������
		return x[1] < y[1];
	}

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())return 0;
		int m = intervals.size();
		sort(intervals.begin(), intervals.end(), cmp);
		//��¼Ҫ�Ƴ�������������
		int temp = intervals[0][1], removed = 0;
		for (int i = 1; i < m; i++) {
			if (intervals[i][0] < temp) {
				removed++;
			}
			else {
				temp = intervals[i][1];
			}
		}
		//��¼Ҫ�Ƴ�������������

		//��¼û���ཻ������������
		temp = intervals[0][1];
		int count = 1;
		for (int i = 1; i < m; i++) {
			if (intervals[i][0] >= temp) {
				count++;
				temp = intervals[i][1];
			}
		}
		//��¼û���ཻ������������
		//�����ַ��������ԣ������¼����Ҫ�Ƴ�����������ֱ�ӷ��ؼ��ɣ������¼���ǲ��ཻ������������󷵻ز�ֵ��
		// �����Ҷ�������������ұ������Ǵ�����������е�Ū����
		//return removed;
		return m - count;
	}
};

//�����ұ߽����򣬾�Ҫ�������ұ�������Ϊ�ұ߽�ԽСԽ�ã�ֻҪ�ұ߽�ԽС��������һ������Ŀռ��Խ�����Դ������ұ���������ѡ�ұ߽�С�ġ�
//������߽����򣬾�Ҫ���������������Ϊ��߽���ֵԽ��Խ�ã�Խ���ң��������͸�ǰһ������Ŀռ��Խ�����Կ��Դ������������
//�ұ߽�����֮�󣬾ֲ����ţ�����ѡ�ұ߽�С�����䣬���Դ������ұ�����������һ������Ŀռ��һЩ���Ӷ��������⽻�档ȫ�����ţ�ѡȡ���ķǽ������䡣

int main() {
	vector<vector<int>> intervals1 = { {1,2},{2,3},{3,4} ,{1,3} };
	vector<vector<int>> intervals2 = { {1,2},{1,2},{1,2} };
	vector<vector<int>> intervals3 = { {1,2},{2,3} };
	Solution s;
	cout << s.eraseOverlapIntervals(intervals1) << endl;
	cout << s.eraseOverlapIntervals(intervals2) << endl;
	cout << s.eraseOverlapIntervals(intervals3) << endl;

	return 0;
}
*/