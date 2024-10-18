#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
            if ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))
                s[i++] = s[j];

        s.erase(s.begin() + i, s.end());

        for (char& c : s)
            if (c >= 'A' && c <= 'Z')
                c = tolower(c);

        int n = s.size();
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};

int main() {
	Solution st;
	string s("A man, a plan, a canal: Panama");
	cout << boolalpha << st.isPalindrome(s) << noboolalpha << endl;
	return 0;
}