#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> res(n);

        for (int i = 0; i < n; i++) {
            string s = arr[i];
            for (int len = 1; len <= s.size(); len++) {
                for (int j = 0; j + len <= s.size(); j++) {
                    string substr = s.substr(j, len);
                    bool b = true;
                    for (int ii = 0; ii < arr.size(); ii++) {
                        if (ii == i)
                            continue;
                        if (arr[ii].find(substr) != -1) {
                            b = false;
                            break;
                        }
                    }
                    if (b &&
                        ((res[i].size() > substr.size()) ||
                            (res[i].size() == substr.size() && res[i] > substr) ||
                            res[i] == ""))
                        res[i] = substr;
                }
            }
        }
        return res;
    }

    // 这是别人的代码，这个代码更合理感觉
    vector<string> shortestSubstrings1(vector<string>& arr) {
        int n = arr.size();

        auto check = [&](int i, string& sub) {
            for (int j = 0; j < n; j++)
                if (j != i && arr[j].find(sub) != -1)
                    return false;
            return true;
            };

        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            int m = arr[i].size();
            string temp;
            for (int len = 1; len <= m && temp.empty(); len++) {  
                // 这个地方添加了一个temp.empty()条件，如果已经找到了一个temp就是len最小的，长度最小且字典序列最小的一定是出现在这个长度，就不继续往len变大的方向遍历了
                for (int j = 0; j + len <= m; j++) {
                    string t = arr[i].substr(j, len);
                    if ((temp.empty() || t < temp) && check(i, t))
                        temp = t;
                }
            }
            res[i] = temp;
        }
        return res;
    }
};

int main() {
	Solution st;
	vector<string> arr{ "gfnt","xn","mdz","yfmr","fi","wwncn","hkdy" };
	vector<string> res = st.shortestSubstrings(arr);
	for (int i = 0; i < arr.size(); i++)
		cout << res[i] << endl;

    cout << "------------" << endl;
    vector<string> res1 = st.shortestSubstrings1(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << res1[i] << endl;
	return 0;
}