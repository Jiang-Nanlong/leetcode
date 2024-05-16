#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//给定一个二维数组，数组中的每一行代表一个房间，房间内的元素是其他房间的钥匙，可以打开其他房间的锁，开始只有第0号房间门开着
//如果能打开所有房间的门就返回true，否则返回false。
//同样可以分为bfs和dfs版，不过这里的dfs分为两个版本，主要区别是在当前层处理当前层的visited数组还是下一层的visited数组

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<bool> visitedRoom(rooms.size(), false);
		queue<int> que;
		que.push(0);
		visitedRoom[0] = true;
		while (!que.empty()) {
			int room = que.front();
			que.pop();
			vector<int> keys = rooms[room];
			if (keys.size() != 0) {
				for (int i : keys) {
					if (visitedRoom[i] == false) {
						visitedRoom[i] = true;
						que.push(i);
					}
				}
			}
		}
		for (int i = 0; i < rooms.size(); i++) {
			if (visitedRoom[i] == false)
				return false;
		}
		return true;
	}

	bool canVisitAllRooms1(vector<vector<int>>& rooms) {
		vector<bool> visitedRoom(rooms.size(), false);
		visitedRoom[0] = true;
		dfs1(rooms, visitedRoom, 0);
		for (int i = 0; i < rooms.size(); i++) {
			if (visitedRoom[i] == false)
				return false;
		}
		return true;
	}

	bool canVisitAllRooms2(vector<vector<int>>& rooms) {
		vector<bool> visitedRoom(rooms.size(), false);
		dfs2(rooms, visitedRoom, 0);
		for (int i = 0; i < rooms.size(); i++) {
			if (visitedRoom[i] == false)
				return false;
		}
		return true;
	}
private:
	void dfs1(vector<vector<int>>& rooms, vector<bool>& visitedRoom, int room) {
		vector<int> keys = rooms[room];
		for (int key : keys) {
			if (visitedRoom[key] == false) {
				visitedRoom[key] = true;
				dfs1(rooms, visitedRoom, key);
			}
		}
	}
	void dfs2(vector<vector<int>>& rooms, vector<bool>& visitedRoom, int room) {
		if (visitedRoom[room] == true)
			return;
		visitedRoom[room] = true;
		vector<int> keys = rooms[room];
		for (int key : keys) {
			dfs2(rooms, visitedRoom, key);
		}
	}

	//第二次做
public:
	// 自己写的代码，感觉也没用到什么算法，其实是用的广度优先搜索
	bool canVisitAllRooms3(vector<vector<int>>& rooms) {
		vector<bool> visited(rooms.size(), false);
		visited[0] = true;
		queue<int> que;
		for (int i = 0; i < rooms[0].size(); i++)
			que.push(rooms[0][i]);

		while (!que.empty()) {
			int num = que.front();
			que.pop();
			if (visited[num] == true) continue;
			visited[num] = true;
			for (int i = 0; i < rooms[num].size(); i++)
				que.push(rooms[num][i]);
		}
		for (bool flag : visited)
			if (flag == false)
				return false;

		return true;
	}

	//dfs写法
	bool canVisitAllRooms4(vector<vector<int>>& rooms) {
		vector<bool> visited(rooms.size(), false);
		visited[0] = true;
		dfs3(rooms, 0, visited);
		for (bool flag : visited)
			if (flag == false)
				return false;

		return true;
	}
	void dfs3(vector<vector<int>>& rooms, int room, vector<bool>& visited) {
		vector<int> keys = rooms[room];
		for (int& key : keys) {
			if (visited[key])
				continue;
			visited[key] = true;
			dfs3(rooms, key, visited);
		}
	}

	// 另一种dfs，但是感觉不如上一种dfs好理解
	bool canVisitAllRooms5(vector<vector<int>>& rooms) {
		vector<bool> visited(rooms.size(), false);

		dfs4(rooms, 0, visited);

		for (bool flag : visited)
			if (flag == false)
				return false;

		return true;
	}
	void dfs4(vector<vector<int>>& rooms, int room, vector<bool>& visited) {
		if (visited[room])
			return;
		visited[room] = true;

		vector<int> keys = rooms[room];
		for (int& key : keys) {
			dfs4(rooms, key, visited);
		}
	}

	//又一次做
public:
	bool canVisitAllRooms6(vector<vector<int>>& rooms) {
		vector<bool> visited(rooms.size(), false);
		queue<int> que;
		que.push(0);

		while (!que.empty()) {
			int key = que.front();
			que.pop();
			if (visited[key])
				continue;
			visited[key] = true;
			for (int& i : rooms[key]) {
				que.push(i);
			}
		}
		for (bool b : visited)
			if (b == false)
				return false;

		return true;
	}
};

int main() {
	Solution st;
	vector<vector<int>> rooms1{ {1},{2},{3},{} };
	vector<vector<int>> rooms2{ {1,3},{3,0,1},{2},{0} };
	cout << boolalpha << st.canVisitAllRooms(rooms1) << endl;
	cout << st.canVisitAllRooms(rooms2) << endl;
	cout << st.canVisitAllRooms1(rooms2) << endl;
	cout << st.canVisitAllRooms2(rooms2) << noboolalpha << endl;
	cout << "----------------" << endl;
	cout << boolalpha << st.canVisitAllRooms3(rooms2) << endl;
	cout << st.canVisitAllRooms4(rooms2) << endl;
	cout << st.canVisitAllRooms5(rooms2) << noboolalpha << endl;
	cout << boolalpha << st.canVisitAllRooms6(rooms2) << noboolalpha << endl;
	return 0;
}