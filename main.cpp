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

    void printGraph() const{
        cout << "Graph's adjacency list: " << endl;
        for (const auto& [node, neighbors]: adjList){
            cout << node << " --> ";
            for (const auto& [neighbor, weight] : neighbors){
                cout << "(" << neighbor << ", " << weight ") ";
            }
            cout << endl;
        }
    }

    void DFS(int start){
        unordered_map<int, bool> visited;
        stack<int> s;
        s.push(start);

        cout << "DFS starting from vertex" << start << endl;
        while (!s.empty()){
            int current = s.top();
            s.pop();

            if(!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                for(auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it){
                    if (!visited[it->first]){
                        s.push(it->first);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int start){

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