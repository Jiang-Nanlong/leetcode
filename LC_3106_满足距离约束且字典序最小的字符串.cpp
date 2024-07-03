#include <iostream>
using namespace std;

// 26����ĸ��ɻ���'z'�����'a'��
// ����һ���ַ���s�����԰��ַ����е��ַ��޸ĳ������ַ������õ�һ���ֵ�������С���ַ��������޸ĺ���ַ�����ԭ�ַ�����Ӧ�ַ�֮��ľ���֮��Ϊk
// ����һ��̰���㷨���⣬Ҫ���޸ĺ���ֵ�������С����ô�ַ�����ߵ��ַ�Ҫ�������޸ĳ�'a'�������ȼ���ԭ�ַ���'a'֮��ľ��룬�������С�ڵ���k����ô�Ϳ��԰�����ַ��޸ĳ�a��ͬʱ�޸�k
// ���ԭ�ַ���'a'֮��ľ������k�ˣ���ô˵����k�������ڣ����ǲ��ܰ�ԭ�ַ��޸ĳ�'a'��ֻ�ܰ�ԭ�ַ���Сk������ΪҪ�ֵ��򾡿���С
// ����С��k��ʱ�򣬿��԰�a�����26����ĸ���м䣬������z,y,x...�����ҿ���b,c,d...������������һ����Сk���ַ���������Խ��a����z,y,x��һ��

class Solution {
public:
    int distance(const char& a, const char& b) {  // ���������ַ�֮��ľ���
        return min(abs(a - b), 26 - abs(a - b));
    }

    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size() && k > 0; i++) {
            int diff = distance(s[i], 'a');
            if (diff <= k) {
                s[i] = 'a';
                k -= diff;
            }
            else {
                s[i] -= k;
                k = 0;
            }
        }
        return s;
    }
};

int main() {
    Solution st;
    string s("zbbz");
    int k = 3;
    cout << st.getSmallestString(s, k) << endl;
    return 0;
}