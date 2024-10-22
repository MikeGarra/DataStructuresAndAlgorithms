#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Graph {
    private:
        // adj = adjacencyList
        unordered_map<string, unordered_set<string> > adjList;
    
    public:
        void printGraph() {
            for (auto [vertex, edges] : adjList) {
                cout << vertex << ": [ ";
                for (auto edge : edges) {
                    cout << edge << " ";
                }
                cout << "]" << endl;
            }
        }

        // Checks if the vertex is already in the adjList
        bool addVertex(string vertex) {
            if (adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;
        }
};

int main() {
    Graph* mygraph = new Graph();

    mygraph->addVertex("A");

    mygraph->printGraph();
}