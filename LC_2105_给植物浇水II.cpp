#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int A = capacityA, B = capacityB;
        int res = 0;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i == j) {
                if (max(A, B) < plants[i])
                    res++;
            }
            else {
                if (A < plants[i]) {
                    A = capacityA;
                    res++;
                }
                A -= plants[i];

                if (B < plants[j]) {
                    B = capacityB;
                    res++;
                }
                B -= plants[j];
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> plants{ 2,2,3,3 };
    int capacityA = 5, capacityB = 5;
    cout << st.minimumRefill(plants, capacityA, capacityB);
    return 0;
}