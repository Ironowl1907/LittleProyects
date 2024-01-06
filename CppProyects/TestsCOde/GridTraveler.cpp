#include<vector>
#include<iostream>
#include<map>

using namespace std;

map<string,long long> memo;

long int gridTraveler(int X, int Y, map<string,long long> &memo){
  if (X == 0 or Y == 0) return 0;
  if (X == 1 and Y == 1 ) return 1;

  string key;
  key += to_string(X) + ',' + to_string(Y);
  if (memo.find(key) != memo.end()) return memo[key];

  memo[key] = gridTraveler(X-1,Y,memo) + gridTraveler(X,Y-1,memo);
  return memo[key];
}

int main (){
  cout << gridTraveler(50,50,memo) << endl;
  return 0;
}