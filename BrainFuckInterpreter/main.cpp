#include <iostream>
#include <vector>

#define LOG(x) std::cout << x << std::endl
#define string std::string

struct Stack{
  std::vector<int> ST;

  void Add(int V){
    ST.push_back(V);
  }
  int Pop(){
    const int poped = ST.back();
    ST.erase(ST.end(),ST.end()+1);
    return poped;
  }

  void PrintStack(){
    for (int a: ST){
      std::cout << a << std::endl;
    }
  }
};

void interpreter(const string &Program){
  std::vector<int> Buffer(1,0);
  int ip = 0;
  int pointer = 0;
  while (ip < Program.size()){
    char ActualInstruction = Program[ip];
    
    switch (ActualInstruction) {
      case '+':
        Buffer[pointer]++;
        if (Buffer[pointer] == 256)
          Buffer[pointer] = 0;
        break;
      case '-':
        Buffer[pointer] --;
        if (Buffer[pointer] == -1)
          Buffer[pointer] = 255;
        break;
      case '>':
        pointer ++;
        if (pointer >= Buffer.size())
          Buffer.push_back(0);
        break;
      case '<':
        if (pointer == 0)
          LOG("[ERROR] Illegal Opertion");
        else pointer --;
        break;
      case '.':
        std::cout <<  (char) Buffer[pointer];
        break;
      case ',':
        char x; std::cin >> x;
        Buffer[pointer] = (int) x;
        break;
    }
    ip++;
  }
  LOG("\n---------------");
  for (int a : Buffer){
    std::cout << a << ' ';
  }
  LOG('\n');
}

int main(){
   interpreter(",.");
}
