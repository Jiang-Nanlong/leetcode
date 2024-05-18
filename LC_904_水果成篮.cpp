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

	//�ڶ�������
	int totalFruit1(vector<int>& fruits) {
		if (fruits.size() < 3)
			return fruits.size();
		unordered_map<int, int> ump;
		int res = 0;
		for (int front = 0, last = 0; front < fruits.size(); front++) {
			ump[fruits[front]]++;
			//if (ump.size() > 2) {  //��ʼ��ʱ����˸�if�жϣ����fruits������ֻ���������Ļ���û������if��䣬��û���޸�res�����ֻ�᷵��0
			//��ʵ����if�жϣ�ֻҪ��res = max(res, front - last + 1);�����������Ҳ����Ӱ������
			while (ump.size() > 2) {
				/*
				if (--ump[fruits[last]] == 0)
					ump.erase(fruits[last]);
				last++;
				*/
				auto it = ump.find(fruits[last]);
				--it->second;
				if (it->second == 0)
					ump.erase(fruits[last]);
				last++;
			}
			res = max(res, front - last + 1);
			//}
		}
		return res;
	}

	// ��������
	int totalFruit2(vector<int>& fruits) {
		int res = 0;
		int slow = 0, fast = 0;
		unordered_map<int, int> umap;
		while (fast < fruits.size()) {
			umap[fruits[fast]]++;
			while (umap.size() > 2) {
				if (--umap[fruits[slow]] == 0) {
					umap.erase(fruits[slow]);
				}
				slow++;
			}
			if (umap.size() <= 2)  // ������<=2����Ϊ�����п���ֻ��һ������
				res = max(res, fast - slow + 1);
			fast++;
		}
		return res;
	}
};

//��ʼ���ŵ���һ���������������ǰ���Ѿ����ڵ����֣�ֻ���Ŵ治���ڵ����⣬��û���Ƕ��٣����Ծ�ѡ��set�����ǻ�������������
//Ȼ���˴𰸲�֪��ʹ��map��Ϊ�����ٶȸ��������õ�unordered_map

int main() {
	Solution st;
	vector<int> nums{ 1,2,3,2,2 };
	int res = st.totalFruit(nums);
	cout << res << endl;
	cout << st.totalFruit1(nums) << endl;
	cout << st.totalFruit2(nums) << endl;

	return 0;
}