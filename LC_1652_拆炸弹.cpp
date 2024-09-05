#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) {
            for (int& i : code)
                i = 0;
        }
        else if (k > 0) {
            vector<int> res(n, 0);
            int sum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            res[0] = sum;
            for (int i = 1; i < n; i++) {
                sum -= code[i];
                sum += code[(i + k) % n];
                res[i] = sum;
            }
            return res;
        }
        else {
            vector<int> res(n, 0);
            int sum = accumulate(code.begin() + k + n, code.end(), 0);
            res[0] = sum;
            for (int i = 1; i < n; i++) {
                sum += code[i - 1];
                sum -= code[(i + k + n - 1) % n];
                res[i] = sum;
            }
            return res;
        }
        return code;
    }
};

int main() {
    Solution st;
    vector<int> code{ 5,7,1,4 };
    int k = 3;
    vector<int> res = st.decrypt(code, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}