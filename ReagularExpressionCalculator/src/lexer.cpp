
#include "../headers/lexer.h"


Token token(std::string value = "", TokenTypes type = Plus){
  return {value, type};
}



// Lexer class definition
  char Lexer::at(){
    return stream[cursor];
  }

  std::vector<Token> Lexer::tokenize(std::string input){
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


