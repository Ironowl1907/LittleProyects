#include<iostream>
#include<vector>

using namespace std;

class Graph{
  public:
    int V;
    vector<vector<int>> adjList;

    Graph(int v) : V(v){
      adjList.reserve(V);
    }

    void addEdge(int src, int dst){
      adjList[src].push_back(dst);
      adjList[dst].push_back(src);
    }

    void DFSExplore(int src){
      int actual;
      vector<int> explored;
      vector<int> queue = {src};
      

      while(!queue.empty()){
        actual = queue.back();
        queue.pop_back();

        for (int a : adjList[actual]){
          if (!explored[a]) queue.insert(queue.begin(),a); cout << a << endl;
        }
      }
    }
};

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
return {2};
}

int main(){
  Graph algo(3);
  algo.addEdge(0,1);
  algo.addEdge(1,2);
  algo.addEdge(2,0);

  algo.DFSExplore(0);
  return 0;
}