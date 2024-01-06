#include <iostream>

using std::cout, std::endl;


struct Node{
  int value;
  Node* Left = nullptr;
  Node* Right = nullptr;
};

void addNode(Node* src, const int &val){
  src -> value = val;
};

void PrintTree(Node* Tree){
  cout << Tree -> value << endl;
  if (Tree -> Left != nullptr)
    PrintTree(Tree ->Left);
  if (Tree -> Right != nullptr)
    PrintTree(Tree ->Right);
}

int main (int argc, char *argv[]) {
  Node* tree = new Node;
  addNode(tree, 1);
  PrintTree(tree);

  delete tree;
  return 0;
}
