#include<iostream>
#include<vector> 
#include<fstream>

using namespace std;


vector<int> calc(vector<int> alturas, int N){
  for (int i = 0; i < alturas.size();i++){
    
  }

  return {0};
}

int main(){
  vector<int> alturas;
  ifstream in("como.in");
  int N;
  in >> N;

  for (int i = 0; i < N;i++){
    int f;
    in >> f;
    alturas.push_back(f);
  }
  int pos;
  in >> pos;

  calc(alturas, N);
  return 0;
}