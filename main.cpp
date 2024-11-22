#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Graph{
private:
    unordered_map<int, vector<pair<int, int>>> adjList;

public:
    void addEdge(int u, int v, int weight){
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    void pointGraph() const{

    }
}

int main(){
    Graph g;

    g.addEdge(0, 1, 12);
    g.addEdge(0, 2, 8);
    g.addEdge(0, 3, 21);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 6, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 5);
    g.addEdge(5, 6, 6);
    g.addEdge(5, 4, 9);

    g.printGraph();

    g.DFS(0);
    g.BFS(0);

    return 0;
}