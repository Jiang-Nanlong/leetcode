#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    //最开始用笨方法做的，但是太耗时了
    string predictPartyVictory(string senate) {
        int num[2] = { 0 };
        int n = senate.size();
        for (char& c : senate)
            if (c == 'R')
                num[0]++;
            else
                num[1]++;

        int index = 0;
        while (num[0] && num[1]) {
            if (senate[index % n] == 'R') {
                int i = index;
                while (senate[i % n] != 'D')
                    i++;
                num[1]--;
                senate[i % n] = 'N';
            }
            else if (senate[index % n] == 'D') {
                int i = index;
                while (senate[i % n] != 'R')
                    i++;
                num[0]--;
                senate[i % n] = 'N';
            }
            index++;
        }
        if (num[0])
            return "Radiant";
        else
            return "Dire";
    }

    // 看了评论区别人的代码，感觉这个思路更好理解，也更快
    string predictPartyVictory1(string senate) {
        int n = senate.size();
        queue<int> RQ, DQ;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                RQ.push(i);
            else
                DQ.push(i);
        }

        while (!RQ.empty() && !DQ.empty()) {
            int rindex = RQ.front();
            RQ.pop();
            int dindex = DQ.front();
            DQ.pop();
            if (rindex < dindex) {
                RQ.push(n + rindex);
            }
            else
                DQ.push(n + dindex);
        }
        if (!RQ.empty())
            return "Radiant";
        return "Dire";
    }
};

int main() {
    Solution st;
    string s("RRDDD");
    cout << st.predictPartyVictory(s) << endl;
    cout << st.predictPartyVictory1(s) << endl;
    return 0;
}