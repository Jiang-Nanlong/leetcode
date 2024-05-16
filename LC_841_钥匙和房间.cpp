#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//����һ����ά���飬�����е�ÿһ�д���һ�����䣬�����ڵ�Ԫ�������������Կ�ף����Դ����������������ʼֻ�е�0�ŷ����ſ���
//����ܴ����з�����žͷ���true�����򷵻�false��
//ͬ�����Է�Ϊbfs��dfs�棬���������dfs��Ϊ�����汾����Ҫ�������ڵ�ǰ�㴦��ǰ���visited���黹����һ���visited����

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

	//�ڶ�����
public:
	// �Լ�д�Ĵ��룬�о�Ҳû�õ�ʲô�㷨����ʵ���õĹ����������
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

	//dfsд��
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

	// ��һ��dfs�����Ǹо�������һ��dfs�����
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

	//��һ����
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