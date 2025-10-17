#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(uint64_t a, uint64_t b, uint64_t c) {
    if (a == 0 || b == 0 || c == 0) return false;
    return (a > c - b) && (a > b - c) && (b > c - a) && (b > a - c) &&
           (c > a - b) && (c > b - a);
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> vec(n + 1);
    for (int i = 0; i < n; i++)
        cin >> vec[i + 1];

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 < 3) {
            cout << "N";
            continue;
        }
        vector<uint64_t> interval(r-l+1);
        for (int j = l; j <= r; j++)
            interval[j-l]=vec[j];

        sort(interval.begin(), interval.end());
        bool flag = false;
        for (int j = 0; j < interval.size() - 2; j++) {
            if (isValid(interval[j], interval[j + 1], interval[j + 2])) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "Y";
        else
            cout << "N";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")