#include <cstdlib>
#include <iostream>


static bool GameOver;
static const int Width = 20;
static const int Lenght = 20;
static int X , Y, FruitX, FruitY, Score;

enum eDirection {
  STOP = 0,
  LEFT = 1,
  RIGHT = 2,
  UP = 3,
  DOWN = 4,
};

eDirection Dir;

void Setup(){
  GameOver = false;
  Dir = STOP;
  X = (int) Width / 2;
  Y = (int) Lenght / 2;
  FruitX = rand() % Width; 
  FruitY = rand() % Lenght; 
}


void Draw(){
  system("clear");
  for (int i = 0; i < Width; i++) std::cout << '#'; // Print walls 
  std::cout << '\n';

  for (int i = 0; i < Lenght; i++){
    for (int ii = 0; ii < Width; ii++){
      if (ii == 0 or ii == Width-1) std::cout << '#';
      else std::cout << ' ';
    }
    std::cout << '\n';
  }

  for (int i = 0; i < Width; i++) std::cout << '#'; // Print walls 
  std::cout << '\n';
  }
  

void Input(){

}
void Logic(){

}
int main(){
  Setup();
  while (!GameOver) {
    Draw();
    Input();
    Logic();
    // Sleep (10);
  }
  return 0;
}
