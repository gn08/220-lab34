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

}