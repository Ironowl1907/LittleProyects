#include<iostream>
#include<vector>

using namespace std;

class Graph{
  public:
    vector<vector<vector<int>>> adjList;
    int V;
  
     Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

  void addVer(int src, int dest, int weight){
    adjList[src].push_back({dest,weight});
    adjList[dest].push_back({src,weight});
  }


  void printGraph(){
    for (int i = 0; i <= adjList.size()-1; i++){
      cout << i << " -> ";
      for (vector<int> a : adjList[i]){
        cout << "(" << a[0] << "," << a[1] << ") ";
      }
      cout << '\n';
    }
  }
};

vector<int> JustExplore(const Graph grafo, const int src){
  vector<int> queue = {src};
  vector<bool> explored(grafo.adjList.size(),false);
  int sel;
  while(!queue.empty()){
    
  }
}


int main (){
  Graph grafo(5);
  grafo.addVer(1,2,5);
  grafo.addVer(2,3,8);
  grafo.addVer(3,4,10);
  grafo.addVer(4,1,11);
  grafo.addVer(4,2,33);
  grafo.printGraph();
  return 0;
}