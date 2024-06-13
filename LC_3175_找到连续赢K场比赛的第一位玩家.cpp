#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

// ����һ��skills���飬�����ڵ�Ԫ�ز���ͬ��ÿ��Ԫ�ر�ʾ��i���˵ļ���ֵ��ǰ������ҽ��б��������ܸ��ߵ�ʤ����ʤ�����ڵ�0λ��ʧ���߼ӵ�ĩβ
// ���ص�һ������Ӯk�ε�ѡ�ֵ���š�

class Solution {
public:
    // �����ҵ�һ�����ģ�ģ���������̡���ʵһ��ʼ���������ˣ�û��ע�⵽Ҫ��������Ӯ��
    // Ȼ�������Ƚϣ���ʵ���ǵ�0λ���κͺ�ߵıȽϣ�Ӯ�ñ����ڵ�һλ�������˵�Ǽ��ڶ�����󣬵��Ǿ���һ�������ıȽ�֮����ʵ���൱��Ӯ�Һ���һ���λ�á�
    // Ȼ��Ϊ�˴ﵽӮ�ô�������������while(1)ѵ����ֻ�дﵽk�β��˳�����ʵ����ȫû�б�Ҫ����Ϊ������һ�ֱȽ�֮�󣬴��ڵ�0λһ����������������ֵ���ӵڶ��ֿ�ʼ��һֱ��������Ӯ��
    // �����һ���Ҳ�����һ������Ӯk�ε��ˣ���ô�����һ���ǵ�һ��֮���ڵ�0λ����

    // ���������������ʱ��
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

    // ���ǿ��ı��˵Ĵ��룬ʹ�õ���˫�˶�����ģ���һ�ֱȽϵĹ���
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

    // �������Լ��Ľ��ķ�����Ҳ�Ͳ���Ҳ��ؼ���ĩβ�����Ǻ͵�0λ����λ��
    int findWinningPlayer2(vector<int>& skills, int k) {
        int n = skills.size();
        vector<int> people(n);  // ������¼ÿ���˵�����
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
