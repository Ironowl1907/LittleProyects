
#include "../headers/lexer.h"


struct Token {
  std::string value;
  TokenTypes type;
};

Token token(std::string value = "", TokenTypes type = Plus){
  return {value, type};
}

class Lexer{
private:
  std::vector<Token> tokens;
  std::string stream = "";
  int cursor = 0;
  char at(){
    return stream[cursor];
  }

public:
  std::vector<Token> tokenize(std::string input = ""){
    stream = input;
    cursor = 0;
    
    // Continue throught no chars
    while (cursor < stream.size()){
      switch (at()) {
        case ' ':
        case '\n':
        case '\t':
          break;
        case '+':
          tokens.push_back(token("+",Plus));
          break;
        case '-':
          tokens.push_back(token("-",Minus));
          break;
        case '*':
          tokens.push_back(token("*",Multiply));
          break;
        case '/':
          tokens.push_back(token("/",Divide));
          break;

        default:
          // Check For numeric value
          std::string num;
          if (isdigit(at())){
            while (isdigit(at())) {
              num += at();
              cursor++;
            }
            tokens.push_back(token(num, Integer));
            cursor--;
            
            break;
          }
          else {
            std::cout << "Invalid token at position " << cursor << ' ' << at() << '\n';
          }
      }

      cursor++;
    }
    tokens.push_back(token("EOF", EndOfFile));
    return tokens;
  }

};

