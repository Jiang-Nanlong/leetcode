//
// Created by cml on 25-2-18.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class RangeFreqQuery {
    unordered_map<int,vector<int>> umap;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
            umap[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        auto it=umap.find(value);
        if(it==umap.end())
            return 0;

        auto &a=it->second;
        return upper_bound(a.begin(),a.end(),right)-lower_bound(a.begin(),a.end(),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {
  vector<int> arr{12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
  RangeFreqQuery s(arr);

  cout<<s.query(1, 2, 4)<<endl;
  cout<<s.query(0, 11, 33)<<endl;
  return 0;
}