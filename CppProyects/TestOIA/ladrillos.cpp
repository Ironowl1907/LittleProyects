#include<iostream>
#include<vector>

using namespace std;



int main (){
  vector<string> hilera = {"1", "*", "4", "*", "*", "18", "*"};

for (int i = 2; i <= hilera.size()-1;i++){
  if (hilera[i-2] == "*" and hilera[i-1] != "*" and hilera[i] != "*") hilera[i-2] = to_string(stoi(hilera[i]) - stoi(hilera[i-1]));
  if (hilera[i-1] == "*" and hilera[i-2] != "*" and hilera[i] != "*") hilera[i-1] = to_string(stoi(hilera[i]) - stoi(hilera[i-2]));
  if (hilera[i] == "*" and hilera[i-2] != "*" and hilera[i-1] != "*") hilera[i] = to_string(stoi(hilera[i-2]) + stoi(hilera[i-1]));
}

  for (string a : hilera){
    cout << a << endl;
  }
  return 0;
}