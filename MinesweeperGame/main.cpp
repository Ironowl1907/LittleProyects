#include <iostream>
#include <vector>

using namespace std;

void printMap(const vector<vector<char>> & map){
  for (int lines = 0; lines < map.size();lines++){
    if (lines >= 9) cout << lines+1 << ' ';
    else cout << lines+1 << "  ";
    for (int columns = 0; columns < map.size();columns++){
      cout << map[lines][columns] << ' ';
    }
    cout << '\n';
  }
}


int main(){
  vector<vector<char>> map(30,vector<char>(30,'.'));
  printMap(map);
  return 0; 
}
