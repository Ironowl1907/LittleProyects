#pragma once

#include <cctype>
#include <string>
#include <vector>
#include <iostream>

enum TokenTypes {
  Plus,
  Minus,
  Multiply,
  Divide,
  Integer,
  EndOfFile
};

struct Token {
public:
  std::string value;
  TokenTypes type;
};

Token token();



class Lexer{
private:
  std::vector<Token> tokens;
  std::string stream = "";
  int cursor = 0;
  char at();

public:
  std::vector<Token> tokenize(std::string input = "");
};
