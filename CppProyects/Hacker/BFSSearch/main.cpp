#include<vector>
#include<iostream>

using namespace std;

class Graph{
  public :
    int V;
    vector<vector<int>> adjList;

    Graph(int v) : V(v){
      adjList.reserve(V);
    }

    void addEdge(int src, int dst){
      adjList[src-1].push_back(dst-1);
      adjList[dst-1].push_back(src-1);
    }

    void printGraph(){
      for (int i = 0; i < V; i++){
        cout << i+1 << " -> ";
        for (int a : adjList[i]){
          cout << a+1 << ' ';
        }
        cout << '\n';
      }
    }
  vector<int> BFSExplore(int src){
    vector<int> visited(V,false);
    vector<int> distance(V,0);
    int actual;
    vector<int> queue = {src -1};

    while (!queue.empty()){
      actual = queue.front();
      queue.erase(queue.begin(),queue.begin()+1);
      visited[actual] = true;

      for (int neighbor : adjList[actual]){
        if (!visited[neighbor]){
          queue.push_back(neighbor);
          distance[neighbor] = distance[actual] + 6;
        }
      }
    }
    distance.erase(distance.begin(),distance.begin()+1);
    return distance;
  }

};

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
  Graph g(n);
  for (vector<int> a : edges){
    g.addEdge(a[0],a[1]);
  }
  vector<int> res = g.BFSExplore(s);
  for (int i = 0; i < res.size();i++){
    if (res[i] == 0) res[i] = -1;
  }
  return res;
}

int main (){
  for (int a : bfs(5,3,{{1,2},{1,3},{2,4}},1)){
    cout << a << endl;
  }
  return 0;
}