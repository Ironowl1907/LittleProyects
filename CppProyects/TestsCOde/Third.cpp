#include<iostream>
#include<vector>

using namespace std;

class Graph{
  public:
  int V;
  vector<vector<vector<int>>> adjList;

    Graph(int v) : V(v){
      adjList.reserve(v+1);
    }

  void printGraph(){
    for (int i = 1; i < adjList.capacity(); i++){
        cout << i << " --> ";
        for (vector<int> a : adjList[i]){
            cout << '(' << a[0] << ',' << a[1] << ')' << ' ';
        }
        cout << '\n';
    }
}

  void addEdge(int src,int dst,int cost){
    adjList[src].push_back({dst,cost});
    adjList[dst].push_back({src,cost});
  }
};


int main (){
  Graph grafo(2);
  grafo.addEdge(1,2,10);
  grafo.printGraph();
  return 0;
}