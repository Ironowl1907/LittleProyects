#include <iostream>
#include <vector>

using namespace std;

struct coords{
  int Y;
  int X;
};

vector<coords> XCalculator (const int &Size){
  vector<coords> CoordList = {{0,0}};

  for (int vert = 1; vert <= Size;vert++){
    CoordList.push_back({0,vert});
    CoordList.push_back({vert,0});
    CoordList.push_back({0,-vert});
    CoordList.push_back({-vert,0});
  }
  return CoordList;
}


int twoPluses(vector<string> grid) {
  int GridYsize = grid.size();
  int GridXsize = grid[0].size();

  int TheXSize = GridYsize >= GridXsize? (GridXsize-1) / 2 : (GridYsize-1) / 2;
  
  vector<coords> ActualCoords;
  while (TheXSize >= 1) { // Reduce the size of te X throught each iteration
    ActualCoords = XCalculator(TheXSize);

    for (int Y = TheXSize; Y <= GridYsize - TheXSize ; Y++){
      for (int X = TheXSize; X <= GridXsize - TheXSize;X++){
        cout << TheXSize << ": " << Y << ' ' << X << endl;
      } 
    }
    TheXSize --;
  }  
  return 0;
}




int main(){
  vector<string> grid(5,string(6,'.'));
  twoPluses(grid);
  return 0;
}
