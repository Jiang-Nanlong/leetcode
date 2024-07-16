#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        priority_queue<ll, vector<ll>, greater<>> pq;
        for (int i : nums)
            pq.push(i);
        while (pq.top() < k) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            pq.push(x * 2 + y);
            res++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,11,10,1,3 };
    int k = 10;
    cout << st.minOperations(nums, k) << endl;
    return 0;
}