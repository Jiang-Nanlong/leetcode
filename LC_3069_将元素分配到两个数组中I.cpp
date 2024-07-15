#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 2, n = nums.size();
        while (i < n) {
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i++]);
            else
                arr2.push_back(nums[i++]);
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 5,4,3,8 };
    vector<int> res = st.resultArray(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}