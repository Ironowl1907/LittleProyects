#include<iostream> 
#include<vector>
#include<set>

using namespace std;

vector<vector<int>> moves = {
  {1,0},
  {1,1},
  {0,1},
  {-1,1},
  {-1,0},
  {-1,-1},
  {0,-1},
  {1,-1}
};

bool posible(int Y, int X, int n){
  bool posY = Y < n and Y >= 0;
  bool posX = X < n and X >= 0;

  return posX and posY;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
  int c = 0;
  r_q --;
  c_q --; // Normalize data
  vector<vector<bool>> matrix(n,vector<bool>(n,false));


  for (vector<int> &a : obstacles){
    cout << a[0]-1 << ' ' << a[1]-1 << endl;
    matrix[a[0]-1][a[1]-1] = true;
  }


  int Y, X;
  for (vector<int> &i : moves){
    cout << "//////// " << i[0] << ' ' << i[1] << endl;
    Y = r_q;
    X = c_q;
    while(true){
      Y += i[0];
      X += i[1];
      
      if (posible(Y,X,n) and matrix[Y][X] == false){
        cout << Y+1 << ' ' << X+1 << endl;
        c++;
      }
      else break;
    }
  }
  return c;
}


int main(){
  cout << queensAttack(100000,0,4187,5068,{}) << endl;
  return 0;
}