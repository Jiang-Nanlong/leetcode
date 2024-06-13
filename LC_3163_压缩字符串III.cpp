#include <iostream>
#include <string>
using namespace std;

// ��ʵ����ͳ���ַ�������������ͬ�ַ��ĸ��������д�ɡ�����+�ַ����ĸ�ʽ�����Ҹ������Ϊ9

class Solution {
public:
    // �о������д���Ĵ����߼���ô���ҵ�ԭ�������ΪҪͨ��fast-slow+1��fast-slow�����㳤�ȣ������͵������һ���ַ��Ĵ����߼����뵥������
    // ��ʹ��count�Ͳ��������������
    string compressedString(string word) {
        string res;
        int slow = 0, fast = 0;
        while (fast <= word.size()) {
            if (fast == word.size()) {
                int len = fast - slow;
                char c = word[fast - 1];
                string str;
                while (len > 9) {
                    str = std::to_string(9) + c;
                    res += str;
                    len -= 9;
                }
                if (len > 0) {
                    str = std::to_string(len) + c;
                    res += str;
                }
                return res;
            }
            if (word[fast + 1] == word[fast]) fast++;
            else {
                int len = fast - slow + 1;
                char c = word[fast];
                string str;
                while (len > 9) {
                    str = std::to_string(9) + c;
                    res += str;
                    len -= 9;
                }
                str = std::to_string(len) + c;
                res += str;
                fast++;
                slow = fast;
            }
        }
        return res;
    }

    string compressedString1(string s) {
        string result;
        int right = 0;
        int n = s.length();

        while (right < n) {
            char c = s[right];
            int count = 1;

            while (right + 1 < n && s[right + 1] == c) {
                right++;
                count++;
            }
            while (count > 9) {
                result += to_string(9) + c;
                count -= 9;
            }
            result += to_string(count) + c;
            ++right;
        }
        return result;
    }

    string compressedString2(string word) {
        string res;
        int count = 1;
        char c = word[0];
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                while (count) {
                    if (count > 9) {
                        res += to_string(9) + c;
                        count -= 9;
                    }
                    else {
                        res += to_string(count) + c;
                        break;
                    }
                }
                count = 1;
                c = word[i];
            }
        }
        while (count) {
            if (count > 9) {
                res += to_string(9) + c;
                count -= 9;
            }
            else {
                res += to_string(count) + c;
                break;
            }
        }
        return res;
    }
};

// compressedString1����õ�
int main() {
    Solution st;
    string s("fffffffffdddddddddddddddddddddddddmmmmooooooooooss");
    string s1("ooooss");
    cout << st.compressedString(s1) << endl;
    cout << st.compressedString1(s1) << endl;
    return 0;
}