#include<vector>
#include<iostream>

using namespace std;

long getWays(int n, vector<long> c) {
  vector<vector<int>> db(c.size()+1,vector<int>(0,1));

  for (vector<int> a : db){
    for (int i : a){
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}

int main(){
  cout << getWays(4,{1,2,3}) << endl;
  return 0;
}