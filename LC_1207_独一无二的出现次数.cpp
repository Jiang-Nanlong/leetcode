// 给定一个有重复项的数组，判断数组中每个元素的出现次数是否不同，如果都不同，返回true，否则返回false
// 1 <= arr.length <= 1000
//- 1000 <= arr[i] <= 1000

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 我自己写的，统计每个元素出现的次数，然后重新排序，判断是否有两个出现次数相同的
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> hash(2001);
        for (int &i : arr)
        {
            hash[1000 + i]++;
        }
        sort(hash.begin(), hash.end());
        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i] != 0 && hash[i] == hash[i - 1])
                return false;
        }
        return true;
    }

    // 代码随想录没有重新排序，而是又用了另一个数组来判断当前次数是否出现过。
    bool uniqueOccurrences2(vector<int> &arr)
    {
        int hash[2001] = {0};
        for (int &i : arr)
        { // 统计每个数字的出现次数
            hash[1000 + i]++;
        }
        bool used[1001] = {false}; // 数组长度最大是1000，所以一个数字的出现次数最大只可能是1000，所以used数组长度为1001
        for (int i = 0; i < 2001; i++)
        { // 遍历hash数组中的出现的每一个次数
            if (hash[i] != 0)
            {
                if (used[hash[i]])
                    return false;
                else
                    used[hash[i]] = true;
            }
        }
        return true;
    }

    //第二次做
    //统计每个元素出现的次数，然后重新排序次数，判断有没有相同的
    bool uniqueOccurrences3(vector<int>& arr) {
        unordered_map<int, int> umap;
        for (int i = 0; i < arr.size(); i++)
            umap[arr[i]]++;

        vector<int> vec;
        for (auto it = umap.begin(); it != umap.end(); it++) {
            vec.push_back(it->second);
        }
        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++)
            if (vec[i] == vec[i - 1])
                return false;

        return true;
    }

    //另一种做法，也是先统计每个数字出现的次数，然后用一个bool数组，统计每个次数是不是已经出现过，如果出现过就直接返回false
    // 这个更好，既不需要重新排序，遍历的次数也更少
    bool uniqueOccurrences4(vector<int>& arr) {
        vector<int> count(2001, 0);    //题目提示中-1000 <= arr[i] <= 1000
        for (int i = 0; i < arr.size(); i++)  //统计每个数字出现的次数
            count[1000 + arr[i]]++;

        vector<bool> appear(1001, false);  //题目提示1 <= arr.length <= 1000，所以每个数字的次数最大不会超过1000次
        for (int i = 0; i < 2001; i++)   //遍历每个次数
            if (count[i] != 0) {
                if (appear[count[i]] == true)
                    return false;
                else
                    appear[count[i]] = true;
            }

        return true;
    }
};

int main()
{
    Solution st;
    vector<int> arr{1, 2, 2, 1, 1, 3};
    cout << boolalpha << st.uniqueOccurrences(arr) << endl;
    cout << st.uniqueOccurrences2(arr) << endl;
    cout << st.uniqueOccurrences3(arr) << endl;
    cout << st.uniqueOccurrences4(arr) << noboolalpha << endl;
    return 0;
}