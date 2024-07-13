#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(),
            [](int& a, int& b) { return a > b; });
        int sum = accumulate(apple.begin(), apple.end(), 0);
        for (int i = 0; i < capacity.size(); i++) {
            if (i > 0)
                capacity[i] += capacity[i - 1];
            if (capacity[i] >= sum)
                return i + 1;
        }
        return capacity.size();
    }
};

int main() {
    Solution st;
    vector<int> apple{ 1,3,2 }, capacity{ 4,3,1,5,2 };
    cout << st.minimumBoxes(apple, capacity) << endl;
    return 0;
}