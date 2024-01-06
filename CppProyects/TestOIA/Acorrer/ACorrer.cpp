#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct Categoria{
  int numero;
  int oro;
  int plata;
  int bronce;
};
struct Competidor{
  int numero;
  char sexo;
};



int main(){
  ifstream archivo("carrera.in"); // Read file
  int A, cf,cm, L;                // Create main variables
  archivo >> A >> cf >> cm >> L;  // Populate main variables

  vector<Categoria> categoriasM;
  vector<Categoria> categoriasF;
  vector<Competidor> competidores;
  vector<int> ganadores;

  for (int i = 0; i < cf;i++){
    int fn,fx;
    categoriasF.push_back({fn,0,0,0});
  }
  for (int i = 0; i < cm;i++){
    int fn,fx;
    archivo >> fn >> fx;
    categoriasM.push_back({fn,0,0,0});
  }

  for (int i = 0; i < L;i++){
    int numero;
    char sexo;
    archivo >> numero >> sexo;
    competidores.push_back({numero,sexo});
  }

  for (int i = 0; i < L;i++){
    int a;
    archivo >> a;
    ganadores.push_back(a);
  }

  return 0;
}
