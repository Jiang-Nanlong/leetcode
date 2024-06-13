#include <iostream>
#include <vector>
using namespace std;

// Ç°×ººÍ

class NumArray {
private:
    vector<int> sum;

public:
    NumArray(vector<int>& nums) {
        this->sum.resize(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return sum[right];
        else
            return sum[right] - sum[left - 1];
    }
};

int main() {
    vector<int> nums{ -2, 0, 3, -5, 2, -1 };
    NumArray* na = new NumArray(nums);
    cout << na->sumRange(0, 2) << endl;
    cout << na->sumRange(2, 5) << endl;
    cout << na->sumRange(0, 5) << endl;
    return 0;
}