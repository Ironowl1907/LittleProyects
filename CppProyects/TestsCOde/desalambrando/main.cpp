//Desalambrando 
#include<iostream>
#include<vector>

using namespace std;

class Graph{
  public:
  int V;
  vector<vector<vector<int>>> adjList;
    Graph(int v) : V(v){
      adjList.reserve(V+1);
    }

    void addEdge(int src, int dst, int cost){
      adjList[src].push_back({dst,cost});
      adjList[dst].push_back({src,cost});
    }

    void printGraph(){
      for (int i = 1; i < adjList.capacity(); i++){
          cout << i << " --> ";
          for (vector<int> a : adjList[i]){
              cout << '(' << a[0] << "," << a[1] << ')' << ' ';
          }
          cout << '\n';
      }
    }

    bool checkCicle(int src, vector<bool> &visited, int parent){
      visited[src] = true;
      cout << "Exploring: " << src << '\n';
      for (vector<int> i : adjList[src]){
        if (!visited[i[0]]) {
          if (checkCicle(i[0], visited, src)) return true;
        }
        else if (i[0] != parent) {
          cout << "Cycle!: " << parent << " and " << src  << endl;
          return true;
        }
      }
      return false;
    }
};

int main (){
  Graph grafoPrincipal(11);
  grafoPrincipal.addEdge(1,4,5);
  grafoPrincipal.addEdge(3,4,6);
  grafoPrincipal.addEdge(2,3,5);
  grafoPrincipal.addEdge(1,2,6);
  grafoPrincipal.addEdge(2,9,9);
  grafoPrincipal.addEdge(8,9,15);
  grafoPrincipal.addEdge(2,8,8);
  grafoPrincipal.addEdge(3,7,9);
  grafoPrincipal.addEdge(3,5,10);
  grafoPrincipal.addEdge(5,6,12);
  grafoPrincipal.addEdge(6,7,10);
  grafoPrincipal.addEdge(7,11,11);
  grafoPrincipal.addEdge(10,11,13);
  grafoPrincipal.addEdge(8,10,14);
  grafoPrincipal.addEdge(7,8,10);
  grafoPrincipal.printGraph();


  vector<bool> visited(12,false);
  cout << grafoPrincipal.checkCicle(1,visited,1) << endl;;

  return 0;
}