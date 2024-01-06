#include<vector>
#include<iostream>

using namespace std;

vector<int> ways(int n, vector<int> coins, vector<int> passed) {
  if (n == 0) return passed;
  if (n < 0) return {};

  for (int i : coins){
    vector<int> arr = passed;
    arr.push_back(i);
    return ways(n - i, coins, arr);
  }
  return arr;
}

int main (){
 cout << ways(4,{1,2,3}) << endl;
  return 0;
}