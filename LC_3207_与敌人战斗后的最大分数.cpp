#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ������enemyEnergies��ʾ���˵���������ʼ����һ������ֵcurrentEnergy��һ��ʼ����Ϊ0�����еĵ��˶�δ��ǡ�
// ����ѡ��һ��δ��ǵĵ��ˣ���currentEnergy >= enemyEnergies[i]ʱ�����һ�֣�currentEnergy -= enemyEnergies[i]��
// �����ǰ������һ�֣�����ѡ��һ��δ��ǵĵ��ˣ���������������currentEnergy += enemyEnergies[i]���õ��˱���ǡ�
// �����������÷֡�

// ��������������Ķ����һ����Ҳ���ǵ�ǰ��������ĳ����������ʱ�����Դ�������һ�֣����ǵ�ǰ��������١���ǰ������һ��ʱ���������ձ��˵�������������˱���ǣ�
// Ҳ����ÿ������ֻ������һ��������
// �������̰���㷨���Ȱѵ��������������α�Ǻ�ߵĵ��ˣ�Ȼ���û�õ������ڵ�0���������ϻ��֡�

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