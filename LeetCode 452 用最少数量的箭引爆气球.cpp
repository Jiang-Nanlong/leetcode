#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�ж����������Ƿ��ص��ܺ��룬�������������Ƿ��ص�����һֱ�벻������ôŪ������Ҫ�Ȱ���߽��������������Ļ��͵ÿ��ǵڶ����������߽��Ƿ�λ��
// ��һ������Ľ����м䣬�������߽��ź����Ժ����Ǵ������۹�ȥ�Ͳ��ÿ��ǵڶ��������߽����һ������߽�֮��Ĵ�С�����ˡ�
//���˴�������¼����Ƶ�����ף�Ҫ�����ұ߽����Сֵ�������һ���������СֵС���ұ߽磬�Ͳ���Ҫ����Ӽ���
//������һ���ط���Ҫע�⣬xstart �� x �� xend����ʾ�����������Ҳ������һ�����䱬

class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];  //����߽��С��������
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		int count = 1;
		sort(points.begin(), points.end(), cmp);
		int minrightmrigin = points[0][1];
		for (int i = 1; i < points.size(); i++) {
			if (points[i][0] > minrightmrigin) {  //����ڶ����������߽������С�ұ߽�
				count++;							//����1�������ұ߽�
				minrightmrigin = points[i][1];
			}
			else {
				minrightmrigin = min(minrightmrigin, points[i][1]);
			}
		}
		return count;
	}
};

int main() {
	Solution st;
	vector<vector<int>> points{ {7,15} ,{6,14},{8,12},{3,4},{4,13},{6,14},{9,11},{6,12},{4,13} };
	int count = st.findMinArrowShots(points);
	cout << count << endl;
	return 0;
}


//������֮ǰд�Ĵ���
/*
��һЩ������XYƽ���ϣ�points�����м�¼�����Ϣ��points[i]=[Xstart,Xend]����¼�������ֱ��������δ���������yֵ����һֻ����x���ĳ����ֱ��x�����������������λ����
�����ֱ���ھͿ��Խ����䱬��������Ժ��������ǰ���������䱬������������Ҫ�����ٵļ���
*/
//������֮ǰ435�Ƴ���С�������������е��񣬶�����������ģ����Ӧ����ͳ���ж������������ص��ģ������ֲ���ֻͳ���ص������ÿ����ص���������һ����С�Ľ���
//��������ֻ��Ҫ���ұ߽�����Ȼ�����ֻ�б������伴�ɣ���Ϊ��ʱ�ʼ�����������С�ģ������ǰ���䲻�����ˣ�����������һ�������С������
/*
class Solution {
public:
	static int cmp(vector<int>& x, vector<int>& y) {   //���ұ߽��������
		return x[1] < y[1];
	}

	//int finMinArrowShots(vector<vector<int>>& points) {
	//	int m = points.size();
	//	if (m == 0) return 0;
	//	sort(points.begin(), points.end(), cmp);
	//	int count = 1, i = 0, temp = points[0][1];
	//	while (i < m) {
	//		if (points[i][0] <= temp && points[i][1] >= temp) {
	//			i++;
	//		}
	//		else {
	//			temp = points[i][1];
	//			count++;
	//			//i++;  ��������Ż�һ������
	//		}
	//	}
	//	return count;
	//}

	int finMinArrowShots(vector<vector<int>>& points) {
		int m = points.size();
		if (m == 0) return 0;
		sort(points.begin(), points.end(), cmp);
		int count = 1, i = 0, temp = points[0][1];
		for (int i = 0; i < m; i++) {
			if (temp < points[i][0]) {
				temp = points[i][1];
				count++;
			}
		}
		return count;
	}
};

int main() {
	vector<vector<int>> points1 = { {1,2},{3,4},{5,6},{7,8} };
	vector<vector<int>> points2 = { {1,2},{2,3},{3,4},{4,5} };
	Solution s;
	cout << s.finMinArrowShots(points1) << endl;
	cout << s.finMinArrowShots(points2) << endl;
	return 0;
}
*/