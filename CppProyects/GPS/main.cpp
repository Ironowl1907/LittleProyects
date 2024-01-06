//Laberinto
#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>> coordsConvertor(vector<vector<int>> arr){
  vector<vector<int>> Narr;
  for (vector<int> cor : arr){

    if (cor[0] == cor[2] and cor[1] != cor[3]){ // i j i k
      for(int i = cor[1]; i <= cor[3];i++){
        Narr.push_back({cor[0],i});
      }
    }
    if (cor[1] == cor[3] and cor[0] != cor[2]){ // k i j i
      for(int i = cor[0]; i <= cor[2];i++){
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


int main(){
  vector<vector<int>> coords = {
    {3 ,1 ,2 ,2},
    {2 ,6 ,2 ,5}, // i j i k
    {3 ,6 ,3 ,6}, // i j i kp
    {7 ,1 ,7 ,3}, // i j i k
    {6 ,1 ,6 ,3}, // i j i k
    {4 ,7 ,5 ,7}, // k i j i
    {6 ,8 ,6 ,8}  
  };
  vector<vector<int>> NCoords = coordsConvertor(coords);

  for (vector<int> a : NCoords){
    for (int i : a){
      cout << i << ' '; 
    }
    cout << '\n';
  }

  vector<vector<char>> map(8, vector<char>(7,'.'));
  
  //Push the obstacles with the cords
	for (int i = 0; i <= NCoords.size()-1;i++){
		map[Ncoords[i][0]-1][Ncoords[i][1]-1] = '+';
	}

  for (vector<char> i : map){
    for (char a : i ){
      cout << a <<  ' ';
    }
    cout << '\n';
  }

  return 0;
}