#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定两个整数数组nums1和nums2，nums1比nums2多两个元素，现在移除这两个元素，剩余nums1和nums2之间的元素差均为x。现找出最小的x

class Solution {
public:
    // 第一种是枚举法，也就是暴力，提示上nums1的长度最大为200，规模不大，可以直接用暴力
    // 也就是先对两个数组排序，然后暴力去除nums1中的两个元素，判断剩余元素与nums2之间的每个数是不是都相差x，
    // 如果是的话就可以作为最小x的备选，如果不是就说明现在去除的两个数不是本该去除的两个数
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int minX = INT_MAX;

        for (int i = 0; i < nums1.size() - 1; i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                vector<int> temp(nums1);
                temp.erase(temp.begin() + j);
                temp.erase(temp.begin() + i);

                int pre = INT_MAX;
                for (int k = 0; k < nums1.size() - 2; k++) {
                    if (k == 0)
                        pre = nums2[k] - temp[k];
                    else {
                        if (nums2[k] - temp[k] != pre) {
                            pre = INT_MAX;
                            break;
                        }
                    }
                }
                minX = min(minX, pre);
            }
        }
        return minX;
    }

    // 因为nums1只比nums2多两个元素，那么这两个元素即便是都在nums1中最小的前三个元素中，前三个元素中还会再剩一个元素，那么现在只需要遍历前三个元素即可
    // 看看前三个元素中哪一个可以作为去除两个元素之后的nums1数组中的最小元素，然后和nums2[0]计算diff，然后再判断剩余的nums1和nums2之间是不是差值相同。
    // 因为这里并没有真去掉两个数，只是选择了nums1中最小的数作为开始，所以nums2一定是以这个最小数开始的nums1数组的子集，所以只需要判断nums2是不是nums1的子集即可。
    int minimumAddedInteger1(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 2; i > 0; i--) {  // 这里只需要判断nums[2]和nums[1]，如果这两个都不是去掉两个元素后的nums1数组的最小元素，那么nums[0]肯定是了
            // 因为要找最小的diff，所以倒序遍历nums1的前三个元素，优先遍历大的，然后nums2[0]-大的nums1[i]就是小的diff
            int diff = nums2[0] - nums1[i];
            int j = 0, k = i;
            while (k < nums1.size() && j < nums2.size()) {
                if (nums1[k] + diff == nums2[j])
                    j++;
                k++;
            }
            if (j == nums2.size())
                return diff;
        }
        return nums2[0] - nums1[0];
    }
};

int main() {
    Solution st;
    vector<int> nums1{ 4, 20, 16, 12, 8 }, nums2{ 14, 18, 10 };
    cout << st.minimumAddedInteger(nums1, nums2) << endl;
    cout << st.minimumAddedInteger1(nums1, nums2) << endl;
    return 0;
}