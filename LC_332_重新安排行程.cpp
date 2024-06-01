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
		for (pair<const string, int>& c : targets[res[res.size() - 1]]) { //����pair�е�string��const��������Ϊ��map�е�key�ǲ������޸ĵ�
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

	//�ڶ�����������û���������������������������ݽṹ���ȿ��Զ��յ�վ�����ֿ��Լ�¼����Ʊ�Ƿ��Ѿ���ʹ�ù�
	//unordered_map<string, map<string, int>> targets;
	vector<string> res;
	bool backtracking(int ticketsNum) {
		if (res.size() == ticketsNum + 1) {
			return true;
		}

		for (pair<const string, int>& target : targets[res[res.size() - 1]]) {
			if (target.second > 0) {
				res.push_back(target.first);
				target.second--;
				if (backtracking(ticketsNum))
					return true;
				target.second++;
				res.pop_back();
			}
		}
		return false;
	}
	vector<string> findItinerary1(vector<vector<string>>& tickets) {
		res.clear();
		targets.clear();
		for (const vector<string>& ticket : tickets) {
			targets[ticket[0]][ticket[1]]++;
		}
		res.push_back("JFK");
		backtracking(tickets.size());
		return res;
	}

	//���������ˣ����ݽṹ������ˣ������벻��ΪɶҪ�з���ֵ
	// ������һ��֪���ˣ�������ֹ������û��һ���ķ��ػ��������Ǽ�������һ�����ִ�У����ֻ�pop_back()
	// Ӧ���и�����ֵ�������������Ӧ��ֱ��һ��㷵��
	vector<string> findItinerary2(vector<vector<string>>& tickets) {
		res.clear();
		unordered_map<string, map<string, int>> TicketHolder;
		for (auto ticket : tickets) {
			TicketHolder[ticket[0]][ticket[1]]++;
		}

		res.push_back("JFK");
		backtracking2(tickets.size(), TicketHolder);
		return res;
	}

	bool backtracking2(int stationNum, unordered_map<string, map<string, int>>& TicketHolder) {
		if (res.size() == stationNum + 1) {
			return true;
		}

		for (auto& ticket : TicketHolder[res.back()]) {
			if (ticket.second > 0) {
				res.push_back(ticket.first);
				ticket.second--;
				if (backtracking2(stationNum, TicketHolder)) return true;
				ticket.second++;
				res.pop_back();
			}
		}
		return false;
	}
};

void main() {
	Solution st;
	vector < vector<string>> tickets{ {"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"} };
	vector<string>res = st.findItinerary2(tickets);
	for (auto& s : res)
		cout << s << " ";
}