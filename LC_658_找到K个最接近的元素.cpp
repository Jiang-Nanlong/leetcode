#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int i = pos - 1, j = pos, n = arr.size();
        vector<int> res(k);
        int index = 0;
        while (i >= 0 && j < n && index < k) {
            if (x - arr[i] <= arr[j] - x)
                res[index++] = arr[i--];
            else
                res[index++] = arr[j++];
        }
        if (index < k) {
            if (i < 0)
                while (index < k)
                    res[index++] = arr[j++];
            else
                while (index < k)
                    res[index++] = arr[i--];
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution st;
    vector<int> arr{ 1,1,1,10,10,10 };
    int k = 1, x = 9;
    vector<int> res = st.findClosestElements(arr, k, x);
    for (int& i : res)
        cout << i << "  ";
    cout << endl;
    return 0;
}