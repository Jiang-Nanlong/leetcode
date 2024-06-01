#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

//给定一份航线列表tickets，其中tickets[i] = [from, to]，表示飞机的出发点和降落点。现在要求重新规划排序，
//把这些行程串起来，从JFK机场出发，如果存在多个有效的行程，按照字典排序返回最小的行程组合。
//一开始看到这个题毫无头绪，怎么也想不到如何用回溯解决，也别提如果有多个有效行程，按照字典排序返回最小行程组合这件事。
//想着转换成树形结构，就可以用回溯了，但是又不知道怎么转换成树形结构。
//看了代码随想录的代码，才知道里边的unordered_map<string, map<string, int>> targets 来统计同一出发点和不同终点之间的关系，并统计出发点到终点的机票数
//同时内层的map<string, int>在统计几个终点是就已经按有序排好了
//有了这个数据结构就能很好的想到树形结构，然后用回溯了，同时如果存在多个有效行程，按照字典排序返回最小行程的问题也解决了

class Solution {
public:
	unordered_map<string, map<string, int>> targets;
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> res;
		for (vector<string>& c : tickets)  //先统计同一起点和不同终点之间的关系，和机票数
			targets[c[0]][c[1]]++;
		res.push_back("JFK");
		Helper(tickets.size(), res);
		return res;
	}

	//关于以往的Helper都没有返回值，而这里却返回bool，因为以往是要统计出各种各样的结果，这里只需要获得一种结果，然后返回就行了，所以这里有返回值
	//当返回true时，就会一路返回到栈顶。
	bool Helper(int ticketsnum, vector<string>& res) {
		if (res.size() == ticketsnum + 1)
			return true;
		for (pair<const string, int>& c : targets[res[res.size() - 1]]) { //这里pair中的string用const修饰是因为，map中的key是不允许被修改的
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

	//第二次做，还是没有做出来，这个题最难想的是数据结构，既可以对终点站排序，又可以记录哪张票是否已经被使用过
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

	//第三次做了，数据结构想出来了，但是想不出为啥要有返回值
	// 调试了一遍知道了，满足终止条件后没有一层层的返回回来，而是继续从上一层继续执行，就又会pop_back()
	// 应该有个返回值，如果满足条件应该直接一层层返回
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