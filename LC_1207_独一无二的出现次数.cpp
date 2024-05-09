// ����һ�����ظ�������飬�ж�������ÿ��Ԫ�صĳ��ִ����Ƿ�ͬ���������ͬ������true�����򷵻�false
// 1 <= arr.length <= 1000
//- 1000 <= arr[i] <= 1000

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // ���Լ�д�ģ�ͳ��ÿ��Ԫ�س��ֵĴ�����Ȼ�����������ж��Ƿ����������ִ�����ͬ��
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

    // ��������¼û���������򣬶�����������һ���������жϵ�ǰ�����Ƿ���ֹ���
    bool uniqueOccurrences2(vector<int> &arr)
    {
        int hash[2001] = {0};
        for (int &i : arr)
        { // ͳ��ÿ�����ֵĳ��ִ���
            hash[1000 + i]++;
        }
        bool used[1001] = {false}; // ���鳤�������1000������һ�����ֵĳ��ִ������ֻ������1000������used���鳤��Ϊ1001
        for (int i = 0; i < 2001; i++)
        { // ����hash�����еĳ��ֵ�ÿһ������
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
};

int main()
{
    Solution st;
    vector<int> arr{1, 2, 2, 1, 1, 3};
    cout << boolalpha << st.uniqueOccurrences(arr) << endl;
    cout << st.uniqueOccurrences2(arr) << noboolalpha << endl;
    return 0;
}