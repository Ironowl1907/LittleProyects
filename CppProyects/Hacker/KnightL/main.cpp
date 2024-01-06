#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<vector<int>> coordMulti{
  {1,1},
  {1,-1},
  {-1,-1},
  {-1,1}
};

vector<vector<int>> allMoves(vector<int> pos, vector<int> mov){
  vector<vector<int>> arr;
  
  for (vector<int> a : coordMulti){
    arr.push_back({pos[0] + mov[0] * a[0], pos[1] + mov[1] * a[1]});
    arr.push_back({pos[0] + mov[1] * a[0], pos[1] + mov[0] * a[1]});
  }

  return arr;
}

bool posible(int N, int Y, int X){
  return Y >= 0 and Y < N and X >= 0 and X < N;
}

vector<vector<int>> DFS(vector<int> src, const int &N, vector<int> &movP,vector<vector<int>> history, set<vector<int>> &visited){
  if (src[0] == N-1 and src[1] == N-1) return history;
  if (src[0] < 0 or src[0] > N or src[1] < 0 or src[1] > N) return {{NULL}};

  visited.insert(src);

  for (vector<int> a : allMoves(src,movP)){
    if (visited.find(a) == visited.end()){
      vector<vector<int>> his = history;
      his.push_back(a);
      vector<vector<int>> res = DFS({a[0],a[1]},N,movP,his,visited);
    }
  }
  return history;
}

// vector<vector<int>> knightlOnAChessboard(int n) {
  
// }

int main(){
  set<vector<int>> visited;
  for (vector<int> a : DFS({0,0},5,{1,2},{},visited)){
    for (int f : a ){
      cout  << f << ' ';
    }
    cout << endl;
  }
    
  return 0;
}