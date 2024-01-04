#include "iostream"
#include "vector"

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


int main(){
  Stack S;
  S.Add(1);
  S.Add(2);
  S.Add(3);
  S.Add(4);
  S.PrintStack();
  S.Pop();
  S.PrintStack();
  return 0;
}
