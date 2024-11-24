#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <limits>

using namespace std;

class Graph{
public:
    map<string, vector<pair<string, int>>> adjList;
    vector<tuple<int, string, string>> edges;
    void addEdge(const string& src, const string& dest, int weight){
        adjList[src].emplace_back(dest, weight);
        adjList[dest].emplace_back(src, weight);
        edges.emplace_back(weight, src, dest);
    }

    void display(){
        cout << "Bus Routes: " << endl;
        cout << "=====================" << endl;
        for (const auto& [stop, neighbors]: adjList){
            cout << "Bus Stop: " << stop << "goes to: " << endl;
            for (const auto& [neighbor, time]: neighbors){
                cout << " to " << neighbor << "[Time: " << time << " ]" << endl;
            }
        }
    }

    void dfs(const string& start) {
        cout << endl << "Route starting from: " << start << endl;
        cout << "===========================================" << endl;
        stack<string> s;
        map<string, bool> visit;

        s.push(start);
        visit[start] = true;

        while (!s.empty()){
            string curr = s.top();
            s.pop();
            cout << "Visiting Stop: " << curr << "\n";

            for(const auto& [neighbor, time] : adjList[curr]){
                if (!visit[neighbor]){
                    s.push(neighbor);
                    visit[neighbor] = true;
                }
            }
        }
    

    }

    void bfs(const string& start) {
        cout << endl << "Inspection from: " << start << endl;
        cout << "=========================================";
        queue<string> q;
        map<string, bool> visit;

        q.push(start);
        visit[start] = true;

        while (!q.empty()){
            string curr = q.front();
            q.pop();
            cout << "Check Stop: " << curr << endl;
            for (const auto& [neighbor, time] : adjList[curr]){
                if (!visit[neighbor]){
                    cout << "  Next Stop: " << neighbor << " [Time: " << time << " ]" << endl;
                    q.push(neighbor);
                    visit[neighbor] = true;
                }
            }
        }
    }

    void shortestPath(const string& start){
        cout << endl << "Shortest path: " << start << endl;
        cout << "==================================" << endl;
        map<string, int> distances;

        for (const auto& [node, _] : adjList) {
            distances[node] = numeric_limits<int>::max();
        }

        set<pair<int, string>> pq;
        distances[start] = 0;
        pq.insert({0, start});

        while (!pq.empty()) {
            auto [currentDist, currentNode] = *pq.begin();
            pq.erase(pq.begin());

            for (const auto& [neighbor, weight] : adjList[currentNode]) {
                int newDist = currentDist + weight;
                if (newDist < distances[neighbor]) {
                    pq.erase({distances[neighbor], neighbor});
                    distances[neighbor] = newDist;
                    pq.insert({newDist, neighbor});
                }
            }

            for (const auto& [node, dist] : distances) {
                cout << start << " -> " << node << " : " << (dist == numeric_limits<int>::max() ? -1 : dist) << endl;
        }
    }}

    void findMinimumTree{
        
    }
};

int main(){
    Graph busGraph;

    busGraph.addEdge("Cliff Street", "Main Station", 10);
    busGraph.addEdge("Cliff Street", "Gym", 15);
    busGraph.addEdge("Main Station", "Library", 5);
    busGraph.addEdge("Main Station", "Gym", 8);
    busGraph.addEdge("Gym", "School", 12);
    busGraph.addEdge("Library", "Mall", 7);
    busGraph.addEdge("School", "Mall", 10);
    busGraph.display();
    busGraph.dfs("Cliff Street");
    busGraph.bfs("Cliff Street");
    busGraph.shortestPath("Cliff Street");

    return 0;
}