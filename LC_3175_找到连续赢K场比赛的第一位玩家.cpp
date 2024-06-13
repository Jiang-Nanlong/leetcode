#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

// 给定一个skills数组，数组内的元素不相同，每个元素表示第i个人的技能值，前两名玩家进行比赛，技能更高的胜出，胜出者在第0位，失败者加到末尾
// 返回第一次连续赢k次的选手的序号。

class Solution {
public:
    // 这是我第一次做的，模拟整个过程。其实一开始理解错题意了，没有注意到要求是连续赢。
    // 然后两两比较，其实就是第0位依次和后边的比较，赢得保持在第一位，输的虽说是加在队伍最后，但是经过一轮完整的比较之后，其实就相当于赢家和输家互换位置。
    // 然后为了达到赢得次数，我设置了while(1)训练，只有达到k次才退出。其实者完全没有必要，因为经过第一轮比较之后，处于第0位一定是整个数组的最大值，从第二轮开始就一直都是它在赢。
    // 如果第一轮找不出第一个连续赢k次的人，那么这个人一定是第一轮之后处于第0位的人

    // 这个方法不合理，超时了
    int findWinningPlayer(vector<int>& skills, int k) {
        vector<int> score(skills.size(), 0);
        unordered_map<int, int> umap;
        for (int i = 0; i < skills.size(); i++)
            umap[skills[i]] = i;
        while (1) {
            for (int i = 1; i < skills.size(); i++) {
                if (skills[0] < skills[i])
                    swap(skills[0], skills[i]);
                if (++score[umap[skills[0]]] == k)
                    return umap[skills[0]];
            }
        }
        return -1;
    }

    // 这是看的别人的代码，使用的是双端队列来模拟第一轮比较的过程
    int findWinningPlayer1(vector<int>& skills, int k) {
        deque<int> dq;
        for (int i = 0; i < skills.size(); i++)
            dq.push_back(i);

        int score = 0, index = 0;

        for (int i = 1; i < skills.size(); i++) {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if (skills[a] < skills[b])
                swap(a, b);

            dq.push_front(a);
            dq.push_back(b);
            if (index != a) {
                index = a;
                score = 0;
            }
            if (++score == k)
                return a;
        }

        return dq.front();
    }

    // 这是我自己改进的方法，也就不输家不必加在末尾，而是和第0位互换位置
    int findWinningPlayer2(vector<int>& skills, int k) {
        int n = skills.size();
        vector<int> people(n);  // 用来记录每个人的索引
        for (int i = 0; i < n; i++)
            people[i] = i;

        int score = 0, winner = 0;
        for (int i = 1; i < n; i++) {
            if (skills[people[0]] < skills[people[i]])
                swap(people[0], people[i]);

            if (winner != people[0]) {
                winner = people[0];
                score = 0;
            }
            if (++score == k)
                return winner;
        }

        return people[0];
    }
};

int main() {
    Solution st;
    vector<int>skills{ 4, 2, 6, 3, 9 };
    int k = 2;
    cout << st.findWinningPlayer2(skills, k) << endl;
    return 0;
}
