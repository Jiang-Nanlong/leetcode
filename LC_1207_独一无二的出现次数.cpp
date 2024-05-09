// ����һ�����ظ�������飬�ж�������ÿ��Ԫ�صĳ��ִ����Ƿ�ͬ���������ͬ������true�����򷵻�false
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

    //�ڶ�����
    //ͳ��ÿ��Ԫ�س��ֵĴ�����Ȼ����������������ж���û����ͬ��
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

    //��һ��������Ҳ����ͳ��ÿ�����ֳ��ֵĴ�����Ȼ����һ��bool���飬ͳ��ÿ�������ǲ����Ѿ����ֹ���������ֹ���ֱ�ӷ���false
    // ������ã��Ȳ���Ҫ�������򣬱����Ĵ���Ҳ����
    bool uniqueOccurrences4(vector<int>& arr) {
        vector<int> count(2001, 0);    //��Ŀ��ʾ��-1000 <= arr[i] <= 1000
        for (int i = 0; i < arr.size(); i++)  //ͳ��ÿ�����ֳ��ֵĴ���
            count[1000 + arr[i]]++;

        vector<bool> appear(1001, false);  //��Ŀ��ʾ1 <= arr.length <= 1000������ÿ�����ֵĴ�����󲻻ᳬ��1000��
        for (int i = 0; i < 2001; i++)   //����ÿ������
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