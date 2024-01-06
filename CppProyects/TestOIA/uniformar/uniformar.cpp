#include<iostream>
#include<fstream>
#include<vector>
#include<set>

using namespace std;

bool isSame(vector<string> arr){
  char last = arr[0][0];
  for (string a : arr){
    for(char f : a){
      if (f != last) return 0;
    }
  }
  return 1;
}

vector<vector<int>> movements = {
  {1,0},
  {-1,0},
  {0,1},
  {0,-1}
};

void changeDFS(vector<int> src, vector<string> &map, set<vector<int>> visited, char dest){
  bool posibleX = src[1] >= 0 and src[1] < map.size();
  bool posibleY = src[0] >= 0 and src[0] < map.size();

  if (!posibleX or !posibleY) return;
  if (visited.find(src) != visited.end()) return;

  if (map[src[0]][src[1]] == dest) return;
  else map[src[0]][src[1]] = dest;

  visited.insert({src[0],src[1]});

  for (vector<int> a : movements){
    if (visited.find({src[0]+a[0],src[1]+a[1]}) != visited.end());
    else changeDFS({src[0]+a[0],src[1]+a[1]},map,visited, dest);
  }
}


int main(){
  fstream in("uniformar.in");

  int N;
  in >> N;

  vector<string> map;

  for (int i = 0; i < N;i++){
    string s;
    in >> s;
    map.push_back(s);
  }
  int c = 0;
  set<vector<int>> visited;
  while(!isSame(map)){
    // for (int i = 0; i < N;i++){
    //   for(int a =0; a < N;a++){
    //     cout << map[i][a] << ' ';
    //   }
    //   cout << endl;
    // }
    c++;
    visited.clear();
    if (map[0][0] == '0') changeDFS({0,0},map,visited,'1');
    else changeDFS({0,0},map,visited,'0');
  }
  ofstream out("uniformar.out");
  out << c;
  out.close();
  in.close();
  cout << c << endl;
  return 0;
}