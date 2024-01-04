#include <iostream>
#include <vector>

#define LOG(x) std::cout << x << std::endl
#define string std::string

void interpreter(string Program){
  std::vector<int> Buffer(1,0);
  int ip = 0;

  while (ip < Program.size()){
    char ActualInstruction = Program[ip];
    int pointer = 0;
    
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
        if (pointer > Buffer.size())
          Buffer.push_back(0);
        break;
      case '<':
        if (pointer == 0)
          LOG("[ERROR] Illegal Opertion");
        else pointer --;
        break;
      case '.':
        std::cout << (char) Buffer[pointer];
        break;
      case ',':
        int x; std:: cin >> x;
        Buffer[pointer] = x;
        break;
    }
  }
}

int main(){
  
}
