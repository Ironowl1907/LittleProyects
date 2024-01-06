#include <iostream>

#define log(x) std::cout << x << std::endl;

struct LLNode{
  int Value;
  LLNode* Link = nullptr;

  LLNode(int value){
    Value = value;
  }
};

void DeleteLinkedList(LLNode* head) {
  while (head != nullptr) {
    LLNode* current = head;
    head = head->Link;
    delete current;
  }
}


LLNode* addNode(LLNode* src, int value){
  LLNode* NewNode = new LLNode(value);
  src -> Link = NewNode;

  return NewNode;
}

void PrintLinkedList(LLNode * src){
  log(src -> Value);
  if (src -> Link != nullptr) PrintLinkedList(src ->Link);
}

int main(){
  LLNode* Head = new LLNode(1);
  addNode(Head,2);
  PrintLinkedList(Head);
  DeleteLinkedList(Head); 
  
  return 0;
}
