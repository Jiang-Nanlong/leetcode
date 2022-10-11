#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i, j, k;
        for (i = 0; i < pieces.size(); i++) {
            int flag = 0;
            for (j = 0; j < pieces[i].size(); j++) {
                for (k = flag; k < arr.size(); k++) {
                    if (pieces[i][j] == arr[k]) {
                        if (flag <= k) {
                            flag = k;
                        }
                        else {
                            return false;
                        }
                    }
                
                }
            }
        }
        if (k == arr.size())
            return false;
        else
            return true;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> arr = { 15,88 };
    vector<vector<int>> pieces = { {88},{15} };
    cout << s->canFormArray(arr, pieces) << endl;

}