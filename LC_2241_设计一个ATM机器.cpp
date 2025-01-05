#include <map>
#include <vector>
using namespace std;

class ATM {
private:
    map<int, int> mp;

public:
    ATM() {
        mp.insert({20, 0});
        mp.insert({50, 0});
        mp.insert({100, 0});
        mp.insert({200, 0});
        mp.insert({500, 0});
    }

    void deposit(vector<int> banknotesCount) {
        int i = 0;
        for (auto& pair : mp) {
            pair.second += banknotesCount[i++];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);
        int i = 4;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it,--i) {
            if (amount >= it->first) {
                int num = amount / it->first;
                res[i]=min(num,it->second);
                amount -= res[i] * it->first;
            }
        }

        if (amount > 0)
            return {-1};

        i = 0;
        for (auto& pair : mp) {
            pair.second -= res[i++];
        }
        return res;
    }
};