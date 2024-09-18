#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个系列公交车的发车时间表，一个乘客排队的数组表示乘客到车站候车的时间点，乘客排队上车。capacity表示车的核载人数
// 你不能和乘客数组中的人到站时间相同，计算可以乘坐最后一班车的最晚到站时间

class Solution {
public:
	int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
		sort(buses.begin(), buses.end());
		sort(passengers.begin(), passengers.end());

		int i = 0;
		int count = 0;
		
		// 人按次序上车
		for (int bus : buses) {
			count = 0;
			while (i < passengers.size() && count < capacity && passengers[i] < bus) {
				i++;
				count++;
			}

		}

		--i;
		int lasttime = 0;
		// 如果最后一辆车没有坐满的话，就从最后一辆车的发车时间往前找，看哪个点可以插队到车站；
		// 如果最后一辆车满了，那就从最后一个乘客的到站时间往前找，看哪个点可以插队
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