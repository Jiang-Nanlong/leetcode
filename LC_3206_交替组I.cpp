#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int res = 0;
        for (int i = 0; i < colors.size(); i++) {
            int n = (i + 1) % colors.size();
            int nn = (i + 2) % colors.size();
            if ((colors[i] == 1 && colors[n] == 0 && colors[nn] == 1) ||
                (colors[i] == 0 && colors[n] == 1 && colors[nn] == 0))
                res++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> colors{ 0,1,0,0,1 };
    cout << st.numberOfAlternatingGroups(colors) << endl;
    return 0;
}