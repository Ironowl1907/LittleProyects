#include <iostream>
#include <fstream>
#include <vector>

using std::cout, std::endl, std::fstream, std::string;
#define log(x) cout << x << endl;

int main(){
  fstream in ("ladrillos.in");
  int N; in >> N;

  std::vector<string> Ladri;
  for (int i = 0; i < N;i++){
    string tempo;
    in >> tempo;
    Ladri.push_back(tempo);
  }
  
  for (string a : Ladri){
    log(a);
  }
  return 0;
}
