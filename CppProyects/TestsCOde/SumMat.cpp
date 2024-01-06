#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> sumVector (vector<vector<int>> arr1, vector<vector<int>> arr2){
  vector<vector<int>> sum;
  vector<int> temp;
  for (int i = 0; i <= arr1.size()-1; i++){
    for (int a = 0; a <= arr1[i].size()-1; a++){
      temp.push_back(arr1[i][a] + arr2[i][a]);
    }
    sum.push_back(temp);
    temp.clear();
  }
  return sum;
}

const int FILAS = 3;
const int COLUMNAS = 3;

int main() {
    const int FILAS = 3;
    const int COLUMNAS = 3;
    int t;
    int matriz[FILAS][COLUMNAS];

    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            cout << "Ingresa el elemento en la posición [" << i << "][" << j << "]: ";
            cin >> t;
            matriz[i][j] = t;
        }
    }

    return 0;
}
