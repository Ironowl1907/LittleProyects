#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
  long minimun = abs(arr[0] - arr[1]);
  
  for (int i = 0; i < arr.size();i++){
    for (int a = i+1; a < arr.size();a++){
       if (abs(arr[i] - arr[a]) < minimun) minimun = abs(arr[i] - arr[a]);
    }
  }
  return minimun;
}

int main(){
  fstream in("algo.algo");
  vector<int> alg;
  int c;
  in >> c;
  for (int i = 0; i < c;i++){
    int a;
    in >> a;
    alg.push_back(a);
  }
  cout << minimumAbsoluteDifference(alg) << endl;
}