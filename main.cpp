#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
    int vertices;
    vector<list<pair<int, int>>> adjacenyList;

public:
    Graph(int v): vertices(v){
        adjacenyList.resive(vertices);
    }
}

int main(){

}