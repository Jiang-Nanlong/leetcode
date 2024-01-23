#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

//����һ�ݺ����б�tickets������tickets[i] = [from, to]����ʾ�ɻ��ĳ�����ͽ���㡣����Ҫ�����¹滮����
//����Щ�г̴���������JFK����������������ڶ����Ч���г̣������ֵ����򷵻���С���г���ϡ�
//һ��ʼ������������ͷ������ôҲ�벻������û��ݽ����Ҳ��������ж����Ч�г̣������ֵ����򷵻���С�г��������¡�
//����ת�������νṹ���Ϳ����û����ˣ������ֲ�֪����ôת�������νṹ��
//���˴�������¼�Ĵ��룬��֪����ߵ�unordered_map<string, map<string, int>> targets ��ͳ��ͬһ������Ͳ�ͬ�յ�֮��Ĺ�ϵ����ͳ�Ƴ����㵽�յ�Ļ�Ʊ��
//ͬʱ�ڲ��map<string, int>��ͳ�Ƽ����յ��Ǿ��Ѿ��������ź���
//����������ݽṹ���ܺܺõ��뵽���νṹ��Ȼ���û����ˣ�ͬʱ������ڶ����Ч�г̣������ֵ����򷵻���С�г̵�����Ҳ�����

class Solution {
public:
	unordered_map<string, map<string, int>> targets;
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> res;
		for (vector<string>& c : tickets)  //��ͳ��ͬһ���Ͳ�ͬ�յ�֮��Ĺ�ϵ���ͻ�Ʊ��
			targets[c[0]][c[1]]++;
		res.push_back("JFK");
		Helper(tickets.size(), res);
		return res;
	}

	//����������Helper��û�з���ֵ��������ȴ����bool����Ϊ������Ҫͳ�Ƴ����ָ����Ľ��������ֻ��Ҫ���һ�ֽ����Ȼ�󷵻ؾ����ˣ����������з���ֵ
	//������trueʱ���ͻ�һ·���ص�ջ����
	bool Helper(int ticketsnum, vector<string>& res) {
		if (res.size() == ticketsnum + 1)
			return true;
		for (pair<const string, int>& c : targets[res[res.size() - 1]]) {
			if (c.second > 0) {
				res.push_back(c.first);
				c.second -= 1;
				if (Helper(ticketsnum, res)) return true;
				c.second += 1;
				res.pop_back();
			}
		}
		return false;
	}
};

void main() {
	Solution st;
	vector < vector<string>> tickets{ {"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"} };
	vector<string>res = st.findItinerary(tickets);
	for (auto& s : res)
		cout << s << " ";
}