#include <bits/stdc++.h>
#include <string>
#include <vector>

#define log(x) std::cout << x << '\n'

enum tokenType  {
  openPar, closePar,
  binaryOperator,
  equals,
  number
};

enum binaryOpperands {
  add,
  rest,
  divi,
  mul
};

struct Token{
  std::string value;
  tokenType type;
};

Token token(std::string value, tokenType type){
  return {value, type};
}

std::string shift (std::string &arr){
  std::string a {arr[0]};
  arr.erase(0,1);
  return a;
}

bool isSikippable (const char &c){
  return (c == ' ' || c == '\t' || c == '\n');
}


std::vector<Token> Tokenize(std::string source){
  std::vector<Token> tokens;
 
  while (source.size() > 0){
    std::string i {source[0]};
    if ( i == "(" ) tokens.push_back(token(shift(source), openPar));
    else if ( i == ")" ) tokens.push_back(token(shift(source), closePar));
    else if ( i == "+" || i == "-" || i == "*" || i == "/" ) tokens.push_back(token(shift(source), binaryOperator));
    else if ( i == "=" ) tokens.push_back(token(shift(source),equals));
    else{
      // Handle multicharacter tokens
      
      // Build number
      if (isdigit(i[0])){
        std::string num = "";
        while (source.size() > 0 && isdigit(source[0])) {
          num += source[0];
          source.erase(0,1);
        }
        tokens.push_back(token(num, number));
      }
      // Ignore spaces, tabs and new lines
      else if (isSikippable(i[0])) source.erase(0,1);
      else {
        std::cout << "Unrecognized character: " << i[0] << std::endl;
      }
    } 
    
  }
  
  return tokens;
}

int main (int argc, char *argv[]) {
  std::string rawSource = "(1 * 2) + 3"; 
  for (Token i  : Tokenize(rawSource)){
    std::cout << i.type << ' ' << i.value << '\n';
  }

  return 0;
}

