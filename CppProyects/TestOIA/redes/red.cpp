#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<set>

using namespace std;

class Graph{
  public:
    map<int,vector<int>> adjList;

    void addEdge(int src, int dst){
      adjList[src].push_back(dst);
      adjList[dst].push_back(src);
    }

    void printGraph(){
      for (auto &i : adjList){
        cout << i.first << " -> ";
        for(auto &a : i.second){
          cout << a << ' ';
        }
        cout << endl;
      }
    }

    bool SearchDFS(int src, set<int> &visited, const int &dst){
      //cout << src << endl;
      if (src == dst) return true;
      visited.insert(src);

      for (auto &a : adjList[src]){
        if(visited.find(a) == visited.end()){
          if (SearchDFS(a,visited,dst)) return true;
        }
      }
      return false;
    }

};


int main (){
  fstream in("red.in");
  ofstream out("res.out");
  char type;
  int src, dst;
  Graph Gmain;


  while (in >> type and  type != 'F'){
     in >> src >> dst;
     cout << src << ' ' << dst << endl;

    if (type == 'C'){
      Gmain.addEdge(src,dst);
    }

    else if (type == 'P'){
      set<int> visited;
      if (Gmain.SearchDFS(src,visited,dst))out << 'S' << endl;
      else out << 'N' << endl;
    }
    else out << "ERRROr "  << type << endl;
    
  }


  return 0;
}