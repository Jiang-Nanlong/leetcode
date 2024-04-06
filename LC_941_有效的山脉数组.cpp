#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //自己用笨方法做的，其实是应该用双指针
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;

        int pack = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > arr[pack])
                pack = i;
        }
        if (pack == 0 || pack == arr.size() - 1)
            return false;

        for (int i = 1; i < pack; i++)
            if (arr[i] <= arr[i - 1])
                return false;

        for (int i = pack + 1; i < arr.size(); i++)
            if (arr[i] >= arr[i - 1])
                return false;

        return true;
    }

    //双指针做法
    bool validMountainArray1(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        int left = 0, right = arr.size() - 1;
        while (left < arr.size() - 1 && arr[left] < arr[left + 1]) left++;
        while (right > 0 && arr[right - 1] > arr[right]) right--;
        if (left == right && left != arr.size() - 1 && right != 0)
            return true;
        return false;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 0,3,2,1 };
    cout << boolalpha << st.validMountainArray(nums) << noboolalpha << endl;
    return 0;
}