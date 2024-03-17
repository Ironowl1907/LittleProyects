#include "../headers/lexer.h"

int main (int argc, char *argv[]) { 
  Lexer lexer;
  std::string input = "10 + 3 * 1";
  for (auto i : lexer.tokenize(input)){
    std::cout << i.value << ' ' << i.type << '\n';
  }

  return 0;
}
