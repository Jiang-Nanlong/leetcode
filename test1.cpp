//
// Created by cml on 25-4-12.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  int res=0;
  for(int i=0;i<n;i++){
     cin>>a[i];
     res+=a[i];
  }

  for(int i=1;i<n;i++){
    if(a[i]<a[i-1]){
      res+=a[i];
    }else if(a[i]==a[i-1])
      res+=a[i]-1;
  }
  cout<<res<<endl;
  return 0;
}