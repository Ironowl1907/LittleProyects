#include "includes.h"

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
