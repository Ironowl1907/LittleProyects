#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjList;


public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        //adjList[dest].push_back(src); // Comment this line if the graph is undirected
    }

    void printGraph() {
        for(int i = 0; i < V; i++) {
            cout << i << " --> "; 
            for(const auto& vertex : adjList[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
    void depthFirstPrint(int source){
      vector<int> stack = {source};
      vector<bool> visited(V,false);
      int current;

      while (!stack.empty()){
        current = stack.back();
        stack.pop_back();
        
        if (!visited[current]) cout << current << endl;
        
        for (int i : adjList[current]){
          if (!visited[current]) stack.push_back(i);
        }
        visited[current] = true;
      }
      
    }

    void breathFirstPrint(int source){
      vector <int> queue = {source};
      vector <bool> visited(V, false);
      int current;
      while (!queue.empty()){
         current = queue[0];
         queue.erase(queue.begin());
         if (!visited[current]) cout << current << endl;
         for (int i : adjList[current]){
           if (!visited[current])queue.push_back(i);
         }
         visited[current] = true;
      }
      
      
    }

    bool isThereDepthFirst(int start, int finish){
      if (start == finish) return true;
      vector<int> stack = {start};
      vector<bool> visited(V,false);
      int current;

      while (!stack.empty()){
        current = stack.back();
        stack.pop_back();
        
        if (!visited[current] and current == finish) return true;
        
        for (int i : adjList[current]){
          if (!visited[current]) stack.push_back(i);
        }
        visited[current] = true;
      }
      return false;
    }

    int maxIsland(){
      int countIsl = 0;
      vector<bool> visited(V,false);

      vector <int> queue = {0};
      int actual;

      for (int i = 0; i <= V-1;i++){
        if (!visited[i]){
          while (!queue.empty()){
            actual = queue.back();
            visited[actual] = true;
            queue.pop_back();
            for (int i : adjList[actual]){
              if (!visited[actual]) queue.insert(queue.begin(),i);
            }
          }
          countIsl ++;
          cout <<  "Test Case1: " << actual << endl;
        }
      }
      return countIsl;
    }

};

int main() {
    Graph graph(9); // Create a graph with X-1 vertices
    graph.addEdge(0,1);
    graph.addEdge(0,8);
    graph.addEdge(0,5);
    graph.addEdge(1,0);
    graph.addEdge(5,0);
    graph.addEdge(5,8);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.addEdge(3,2);
    graph.addEdge(3,4);
    graph.addEdge(4,3);
    graph.addEdge(4,2);
    graph.addEdge(8,0);
    graph.addEdge(8,5);



    graph.printGraph();
    cout << endl;
  cout <<graph.maxIsland() << endl;

    return 0;
}
