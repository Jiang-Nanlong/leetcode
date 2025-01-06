//
// Created by ≤‹√œ¡˙ on 25-1-6.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int prev = bottom;
        int res = 0;
        for (const int& i : special) {
            res = max(res, i - prev);
            prev = i + 1;
        }
        res = max(res, top - special.back());

        return res;
    }
};

int main(){
    Solution st;
    int bottom=2;
    int top=9;
    vector<int> special{4,6};
    cout<<st.maxConsecutive(bottom,top,special)<<endl;

    return 0;
}