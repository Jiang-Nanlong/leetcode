#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* ����⻹��һ���������ڵ��⣬������˼���û�����ף��������ϲ�֪����Ҫ��ɶ������һ������fruits���������ÿһ��Ԫ�ض���һ������������ͷ��ʼ��������������ֻ�������������ҳ����������������󳤶ȡ�
*/
class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		int i = 0, j = 0, count = 0, result = 0;
		unordered_map<int, int> ump;
		for (; j < fruits.size(); j++) {
			ump[fruits[j]]++;
			while (ump.size() > 2) {
				/*
				ump[fruits[i]]--;
				if(ump[fruits[i]]==0)
					ump.erase(fruits[i]);
				i++;
				*/
				auto it = ump.find(fruits[i]);			//�����Աȷ��֣����ַ������죬���ϱߵĿ�һЩ
				--it->second;
				if (it->second == 0)
					ump.erase(it);
				i++;
			}
			result = max(result, j - i + 1);
		}
		return result;
	}
};

//��ʼ���ŵ���һ���������������ǰ���Ѿ����ڵ����֣�ֻ���Ŵ治���ڵ����⣬��û���Ƕ��٣����Ծ�ѡ��set�����ǻ�������������
//Ȼ���˴𰸲�֪��ʹ��map��Ϊ�����ٶȸ��������õ�unordered_map

int main() {
	Solution st;
	vector<int> nums{ 1,2,3,2,2 };
	int res = st.totalFruit(nums);
	cout << res << endl;
	return 0;
}