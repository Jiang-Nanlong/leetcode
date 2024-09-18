#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ��ϵ�й������ķ���ʱ���һ���˿��Ŷӵ������ʾ�˿͵���վ�򳵵�ʱ��㣬�˿��Ŷ��ϳ���capacity��ʾ���ĺ�������
// �㲻�ܺͳ˿������е��˵�վʱ����ͬ��������Գ������һ�೵������վʱ��

class Solution {
public:
	int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
		sort(buses.begin(), buses.end());
		sort(passengers.begin(), passengers.end());

		int i = 0;
		int count = 0;
		
		// �˰������ϳ�
		for (int bus : buses) {
			count = 0;
			while (i < passengers.size() && count < capacity && passengers[i] < bus) {
				i++;
				count++;
			}

		}

		--i;
		int lasttime = 0;
		// ������һ����û�������Ļ����ʹ����һ�����ķ���ʱ����ǰ�ң����ĸ�����Բ�ӵ���վ��
		// ������һ�������ˣ��Ǿʹ����һ���˿͵ĵ�վʱ����ǰ�ң����ĸ�����Բ��
		if (count < capacity)
			lasttime = buses.back();
		else
			lasttime = passengers[i];

		while (i >= 0 && lasttime == passengers[i]) {
			lasttime--;
			i--;
		}

		return lasttime;
	}
};


int main() {
	Solution st;
	vector<int> buses{ 20,30,10 }, passengers{ 19,13,26,4,25,11,21 };
	int capacity = 2;
	cout << st.latestTimeCatchTheBus(buses, passengers, capacity) << endl;
	return 0;
}