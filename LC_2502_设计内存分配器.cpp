//
// Created by ≤‹√œ¡˙ on 25-2-25.
//
#include <cstdint>
#include <vector>
using namespace std;

class Allocator {
    vector<uint16_t> vec;

public:
    Allocator(int n) : vec(n) {
    }

    int allocate(int size, int mID) {
        int count = 0;
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            if (vec[i] != 0) {
                count = 0;
            } else {
                ++count;
                if (count == size) {
                    fill(vec.begin() + (i - size + 1), vec.begin() + (i + 1), mID);
                    return i - size + 1;
                }
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int count = 0;
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            if (vec[i] == mID) {
                vec[i] = 0;
                count++;
            }
        }
        return count;
    }
};

int main() {
    Allocator st(5);
    return 0;
}
