#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个数组enemyEnergies表示敌人的能量，开始给定一个能量值currentEnergy。一开始分数为0，所有的敌人都未标记。
// 可以选择一个未标记的敌人，当currentEnergy >= enemyEnergies[i]时，获得一分，currentEnergy -= enemyEnergies[i]；
// 如果当前至少有一分，可以选择一个未标记的敌人，吸收他的能量，currentEnergy += enemyEnergies[i]，该敌人被标记。
// 返回最后的最大得分。

// 这个题做起来跟阅读理解一样，也就是当前能量大于某个敌人能量时，可以打败它获得一分，但是当前能量会减少。当前至少有一分时，可以吸收别人的能量，这个敌人被标记，
// 也就是每个敌人只能吸收一次能量。
// 这题就是贪心算法，先把敌人能量排序，依次标记后边的敌人，然后用获得的能量在第0个敌人身上积分。

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < enemyEnergies[0])
            return 0;

        long long res = currentEnergy / enemyEnergies[0];
        currentEnergy %= enemyEnergies[0];
        for (int i = 1; i < enemyEnergies.size(); i++) {
            currentEnergy += enemyEnergies[i];
            res += currentEnergy / enemyEnergies[0];
            currentEnergy %= enemyEnergies[0];
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> enemyEnergies{ 3,2,2 };
    int currentEnergy = 2;
    cout << st.maximumPoints(enemyEnergies, currentEnergy) << endl;
    return 0;
}