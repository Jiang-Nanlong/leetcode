#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ������൱��LeetCode 1201 ����III�ĸ�һ�㻯�汾������III��ֻ����������
// ����Ӧ�û���һ������֪ʶ������һ����m���ж��ٸ���������n��ɵ����֣���m/n�����������Ϊ��m�ȷ֣�ÿһ�ݶ���n������m/n�ݣ�������Щ��n��ɵ����ֿ�����n,2n,3n...m/n*n
// �����������أ�Ҳ����һ����m���ж��ٸ������ȿ�����n1��ɣ�Ҳ������n2��ɣ� ��m/lcm(n1,n2)��
// ���Զ��ڶ���1�������飬��һ����m�ķ�Χ���ж��ٸ������Ա������е�����������Ҫ�õ��ݳ�ԭ��

class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b) { // �����������
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) { // ��С������
        return a * b / gcd(a, b);
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto calc = [&](long long target) {   // �ݳ�ԭ�����һ����target���ж��ٸ������Ա�coins�е�Ԫ������
            long long res = 0;
            for (int i = 1; i < (1 << n); i++) {  // ö��coins�����зǿ��Ӽ�����������i�е�1������Щcoins�е�Ԫ�ر�ѡ��
                int sign = -1;
                long long Least_Common_Multiple = 1;  // ��С������
                for (int j = 0; j < n; j++) {  // ����coins�е�ÿһ��Ԫ��
                    if (i & (1 << j)) {   // �жϸ�Ԫ���ǲ������Ӽ�i�е�Ԫ��
                        Least_Common_Multiple = lcm(Least_Common_Multiple, coins[j]);   // ���µ�ǰ�Ӽ�����С������
                        sign = -sign;  // ÿһ�ζ���ת���ţ�����Ϊ����ż��λ��
                    }
                }
                res += sign * (target / Least_Common_Multiple);  
            }
            return res;
        };

        sort(coins.begin(), coins.end());
        long long left = 1, right = 1LL * coins.back() * k;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (calc(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    Solution st;
    vector<int> coins{ 3, 6, 9 };
    int k = 3;
    cout << st.findKthSmallest(coins, k) << endl;
    return 0;
}