#include<vector>
#include<iostream>
#include<map>

using namespace std;

map <int,bool> memo;

bool canSum(int N, vector<int> arr,map<int,bool> memo){
  if (memo.find(N) != memo.end()) return memo[N];
  if (N == 0) return true;

  for (int i : arr){
    int rest = N -i;
    if (rest < 0) return false;
    memo[N] = canSum(rest,arr, memo);
    return memo[N];
  }
  return false;
}

int main (){
  cout << canSum(300,{7,14},memo) << endl;
  return 0;
}