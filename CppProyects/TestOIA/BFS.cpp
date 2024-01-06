#include<iostream>
#include<vector>

using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int V;

    Graph(int v) : V(v) {
        adjList.resize(V);
    }

    void addEdge(int src, int dst) {
        adjList[src].push_back(dst);
        adjList[dst].push_back(src);
    }

    

    int bfsExplorer(int src, int dst){
      vector<bool> explored(V,false);
      vector<int> current;
      vector<vector<int>> queue = {{src,0}};

      while (!queue.empty()){
        current = queue.front();
        if (current[0] == dst) return current[1];
        queue.erase(queue.begin());

        for (int neighbor : adjList[current[0]]){
          if (!explored[neighbor]){
            queue.push_back({neighbor,current[1]+6});
            
          }
        }
        explored[current[0]] = true;
      }
      return -1;
    }
};



vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
  int result;
  Graph mainG(n+1);
  for (vector<int> adj : edges){
    mainG.addEdge(adj[0], adj[1]);
  }
  vector<int> results;
  for (int i = 1; i <= n; i++){
    if (i != s) results.push_back(mainG.bfsExplorer(s,i));
  }
  

  return results;
}
int main (){
  for (int i : bfs(5,3,{{1,2},{1,3},{3,4}},1)){
    cout << i << ' ';
  }
  return 0;
}