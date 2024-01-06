#include<iostream>
#include<vector>

using namespace std;

class Graph{
  int V;
  vector<vector<int>> adjList;

  public:
    Graph(int Ver): V(Ver){
      adjList.reserve(V);
    }

    void addEdge(int src, int dest){
      adjList[src].push_back(dest);
      adjList[dest].push_back(src); // Coment this line if directed graph
    }

    void printGraph(){
      for (int i = 0; i <= V-1; i++){
        cout << "Vertex: " << i << " ->";
        for (int a : adjList[i]){
          cout << " " << a;
        }
        cout << endl;
      }
    }

    void exploreDepthFirstTraversalDirected(int src){
      cout << src << endl;
      for (int neighbor : adjList[src]){
        exploreDepthFirstTraversalDirected(neighbor);
      }
    }

    int ShortestPathUndirected(int src, int dest){
      vector<bool> visited(V,false);
      vector<vector<int>> queue = {{src,0}};
      vector<int> actual = queue.front();
      for (int i : actual){
        cout << "[" << i << "]";
      }
      cout << endl;
      while(!queue.empty()){
        actual = queue.front();
        queue.erase(queue.begin());
        for (int i : actual){
          //cout << "adding" << endl;
          if (!visited[actual[0]]) queue.push_back({i, actual[0]+1});
        }
      }
      return 0;
    }
};


int main(){
  Graph graph(5);
  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(1,3);
  graph.addEdge(3,4);
  graph.addEdge(2,4);

  graph.printGraph();
  cout << endl;
  graph.ShortestPathUndirected(0,4);

  return 0;
}