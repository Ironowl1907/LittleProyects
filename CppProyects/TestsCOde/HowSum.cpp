#include<iostream>
#include<vector>

using namespace std;

vector<int> howSum(int N, vector<int> arr){
  if (N == 0) return {};
  if (N < 0) return {};
  for (int i : arr){
    int remainder = N - i;
    vector<int> Fremainder = howSum(i, arr);
    if (!Fremainder.empty()){
      Fremainder.push_back(i);
      return Fremainder;
    }
  }
  return {};
}

int main (){
  for (int i : howSum(7,{2,3})){
    cout << i << endl;
  }
  return 0;
}