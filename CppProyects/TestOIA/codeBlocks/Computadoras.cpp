#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Graph{
    public:
        map <int,vector<int>> adjList;

        void addEdge(int src, int dst){
            adjList[src].push_back(dst);
        }
};



int main(){

return 0;
}
