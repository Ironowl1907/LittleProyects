#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(){
  fstream file("mural.in");
  int T, PH, PD;
  file >> T >> PH >> PD;

  vector<vector<char>> muro(T,vector<char>(T,'.'));

  for (int  i = 0; i < PH;i++){
    int a,c,d;
    char b;
    file >> a >> b >> c >> d;

    for (int color = c; color <= d; color ++){
      muro[a-1][color-1] = b;
    }
  }

  vector<vector<char>> muro1(T,vector<char>(T,'.'));
  for (int  i = 0; i < PD;i++){
    int a,c,d;
    char b;
    file >> a >> b >> c >> d;

    for (int color = c; color <= d;color++){
      muro1[color-1][a-1] = b;
    }
  }


  vector<vector<char>> muroF(T,vector<char>(T,'.'));
  for (int i = 0; i < T;i++){
    for (int a = 0; a < T;a++){
      if (muro[i][a] == muro1[i][a]) muroF[i][a] = muro1[i][a];
      if (muro[i][a] == muro1[i][a]) muroF[i][a] = muro[i][a];

      if (muro[i][a] != '.' and muro1[i][a] == '.') muroF[i][a] = muro[i][a];
      if (muro[i][a] == '.' and muro1[i][a] != '.') muroF[i][a] = muro1[i][a];
      
      if (muro[i][a] == 'R' and muro1[i][a] == 'Z' or muro[i][a] == 'Z' and muro1[i][a] == 'R') muroF[i][a] = 'P';
      if (muro[i][a] == 'R' and muro1[i][a] == 'A' or muro[i][a] == 'A' and muro1[i][a] == 'R') muroF[i][a] = 'N';
      if (muro[i][a] == 'A' and muro1[i][a] == 'Z' or muro[i][a] == 'Z' and muro1[i][a] == 'A') muroF[i][a] = 'V';
    }
  }
  ofstream out("mural.out");

  for (vector<char> f: muroF){
    for (char a : f){
      out << a;
    }
    out << endl;
  }
  return 0;
}