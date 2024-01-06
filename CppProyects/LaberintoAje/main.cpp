#include <iostream>
#include<vector>

using namespace std;

bool simpleFind(vector<vector<int>> arr, vector<int> val){
  for (vector<int> a : arr){
    if (a == val) return true;
  }
  return false;
}

vector<vector<int>> coordsConvertor(vector<vector<int>> arr){
  vector<vector<int>> Narr;
  for (vector<int> cor : arr){

    if (cor[0] == cor[2] and cor[1] != cor[3]){
      int start = min(cor[1], cor[3]);
      int end = max(cor[1], cor[3]);
      for(int i = start; i <= end; i++){
        Narr.push_back({cor[0],i});
      }
    }
    else if (cor[1] == cor[3] and cor[0] != cor[2]){ 
      int start = min(cor[0], cor[2]);
      int end = max(cor[0], cor[2]);
      for(int i = start; i <= end; i++){
        Narr.push_back({i,cor[1]});
      }
    }
    else{
      Narr.push_back({cor[0],cor[1]});
      Narr.push_back({cor[2],cor[3]});
    }
  }
  return Narr;
}

vector<vector<char>> mapCreator(vector<vector<int>> coords, int M){
	vector<vector<char>> map(M,vector<char>(M,'.'));
	
	for (int i = 0; i <=coords.size()-1; i++){
		map[coords[i][0]-1][coords[i][1]-1] = '+';
	}
	return map;
}

//////////////////////////////////////////////////////////////
////////////////////////GOOD PART/////////////////////////////
//////////////////////////////////////////////////////////////

vector<vector<int>> movements = {
    // Possible movements for the bishop (alfil)
    {1, 1, 2},     // Diagonal movement (up-right)
    {1, -1, 2},    // Diagonal movement (up-left)
    {-1, 1, 2},    // Diagonal movement (down-right)
    {-1, -1, 2},   // Diagonal movement (down-left)

    // Possible movements for the rook (torre)
    {0, 1, 3},     // Horizontal movement (right)
    {0, -1, 3},    // Horizontal movement (left)
    {1, 0, 3},     // Vertical movement (up)
    {-1, 0, 3},    // Vertical movement (down)

    // Possible movements for the knight (caballo)
    {1, 2, 2},     // L-shaped movement (right-up)
    {2, 1, 2},     // L-shaped movement (up-right)
    {2, -1, 2},    // L-shaped movement (up-left)
    {1, -2, 2},    // L-shaped movement (left-up)
    {-1, -2, 2},   // L-shaped movement (left-down)
    {-2, -1, 2},   // L-shaped movement (down-left)
    {-2, 1, 2},    // L-shaped movement (down-right)
    {-1, 2, 2}     // L-shaped movement (right-down)
};

int shortesDFS(int N ,int X, int Y, int dst, vector<vector<int>> coords, vector<int> last, vector<int> last2){
  bool YPosible = X >= 0 and X < N;
  bool XPosible = Y >= 0 and Y < N;

  if (!YPosible or !XPosible) return 0; // If the movement is posble

  if (simpleFind(coords, {Y,X})) return 0; // if there isn't any obstacle

  
}

int main (){
	vector<vector<int>> coords = {
    {3 ,1 ,2 ,2},
    {2 ,6 ,2 ,5}, // i j i k
    {3 ,6 ,3 ,6}, // i j i k
    {7 ,1 ,7 ,3}, // i j i k
    {6 ,1 ,6 ,3}, // i j i k
    {4 ,7 ,5 ,7}, // k i j i
    {6 ,8 ,6 ,8}  
  };

	vector<vector<int>> NCoords = coordsConvertor(coords);

	return 0;
}