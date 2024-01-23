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