//
// Created by ²ÜÃÏÁú on 25-2-24.
//
#include <vector>
#include <string>
using namespace std;

class OrderedStream {
    vector<string> vec;
    int ptr;

public:
    OrderedStream(int n) : vec(n + 1), ptr(1) {
    }

    vector<string> insert(int idKey, string value) {
        vec[idKey] = move(value);

        int left = ptr;
        while (ptr < vec.size() && !vec[ptr].empty())
            ptr++;

        return {vec.begin() + left, vec.begin() + ptr};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
    return 0;
}
