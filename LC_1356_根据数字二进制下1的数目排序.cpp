#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countof1(int x) {
        int count = 0;
        while (x) {
            if (x & 1) count++;
            x = x >> 1;
        }
        return count;
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> vec;
        for (int i : arr) {
            vec.push_back({ countof1(i),i });  // vec[i][0]表示1的数目，vec[i][1]表示对应的数字
        }
        sort(vec.begin(), vec.end(), cmp);

        vector<int> res;
        for (int i = 0; i < vec.size(); i++) {
            res.push_back(vec[i][1]);
        }
        return res;
    }
};

//代码随想录的方法，这个更简单，直接在原数组上排序
class Solution1 {
public:
    static int countof1(int x) {
        int count = 0;
        while (x) {
            if (x & 1)
                count++;
            x = x >> 1;
        }
        return count;
    }
    static bool cmp(int& a, int& b) {
        int countA = countof1(a);
        int countB = countof1(b);
        if (countA == countB)
            return a < b;
        return countA < countB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

int main() {
    Solution st;
    vector<int> arr{ 1024,512,256,128,64,32,16,8,4,2,1 };
    vector<int> res = st.sortByBits(arr);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    Solution1 st1;
    vector<int> arr1{ 1024,512,256,128,64,32,16,8,4,2,1 };
    vector<int> res1 = st1.sortByBits(arr1);
    for (int i : res1)
        cout << i << " ";
    cout << endl;
    return 0;
}