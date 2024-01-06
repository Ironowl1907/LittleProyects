#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool startsWith(string a, string b){
  a.resize(b.size());
  if (a == b) return true;
  return false;
}

int canConstruct(string str, vector<string> arr){
  if (str == "") return 1;

  for (string let : arr){
    if (startsWith(str, let)){
      string str2 = str;
      str2.erase(str2.begin(),str2.begin() + let.size());
      Nways = canConstruct(str2,arr);
      Tcount += Nways;
    }
  }
  return Tcount;
}

int Nways = 0;
int Tcount = 0;

int main (){
  
  
  return 0;
}
