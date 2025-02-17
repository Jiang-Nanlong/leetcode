//
// Created by cml on 25-2-17.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                if (++count > n / 4)
                    return arr[i];
            } else
                count = 1;
        }
        return arr[0];
    }
};

int main() {
    Solution st;
    vector<int> arr{1, 2, 2, 6, 6, 6, 6, 7, 10};
    cout << st.findSpecialInteger(arr) << endl;
    return 0;
}
