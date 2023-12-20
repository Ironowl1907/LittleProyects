#include "iostream"
#include <vector>
using namespace std;

char gameState = '.';

void PrintMap(const vector<char> map){
  for (int i = 0; i < map.size();i += 3){
    cout << " | " << map[i] << ' ' << map[i+1] << ' ' << map[i+2] << " |\n";
  }
}

char TerminatedAndWin(const vector<char> & map){
  for (int i = 0; i < 3; i++){

    // Check for horizontal patterns
    if (map[i] == map[i+1] and map[i] == map[i+2]) gameState = map[i];

    // Check for vertical patterns
    if (map[i] == map[i+3] and map[i] == map[i+6]) gameState = map[i];

    // Checck for diagonal patterns
    if (map[0] == map[4] and map[0] == map[8]) gameState = map[0];
    if (map[2] == map[4] and map[2] == map[6]) gameState = map[2];

  }
  return gameState;
}

void CurrentPlayingGame(vector<char> & map){
  while (gameState == '.'){
    int space;
    while (true){
      cout << "[X] Select a space: (ak: 1-9)" << '\n';
      cin >> space; 
      if (space < 0 or 0 > 9) cout << "\nIncorrect selection, please retry\n";
      else break;
    }
    map[space - 1] = 'X';
    PrintMap(map);
    TerminatedAndWin(map);
    
    if (gameState != '.') break;

    while (true){
      cout << "[0] Select a space: (ak: 1-9)" << '\n';
      cin >> space; 
      if (space < 0 or 0 > 9) cout << "\nIncorrect selection, please retry\n";
      else break;
    }
    map[space - 1] = '0';
    PrintMap(map);
    TerminatedAndWin(map);
  }
  cout << gameState << " Is the winner!!" << endl;
}

int main(){
  vector<char> map(9,'.');
  PrintMap(map);
  CurrentPlayingGame(map) ;
  return 0;
}
