#include<iostream>
#include<vector>

using namespace std;


int sendero(int B, int G, int N, string  &baldosas) {
    int costo = 0;

    for (int i = 0; i < baldosas.size(); ++i) {
        if (baldosas[i] == 'R') {
            // Si la baldosa es removida, busca el color más barato disponible
            if ((i == 0 || baldosas[i - 1] != 'B') && (i == baldosas.size() - 1 || baldosas[i + 1] != 'B')) {
                baldosas[i] = 'B';
                costo += B;  // Suma el precio de la baldosa B al costo total
            } else if ((i == 0 || baldosas[i - 1] != 'G') && (i == baldosas.size() - 1 || baldosas[i + 1] != 'G')) {
                baldosas[i] = 'G';
                costo += G;  // Suma el precio de la baldosa G al costo total
            } else {
                baldosas[i] = 'N';
                costo += N;  // Suma el precio de la baldosa N al costo total
            }
        }
    }

    return costo;
}


int main(){
  string a = "RGNRRNRRRBRN";
  cout << sendero(1,2,3,a) << endl;
  return 0;
}