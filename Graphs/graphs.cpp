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

        bool addEdge(string vertex1, string vertex2) {
            if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList.at(vertex1).insert(vertex2);
                adjList.at(vertex2).insert(vertex1);
                return true;
            }
            return false;
        }

        bool removeEdge(string vertex1, string vertex2) {
            if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
                return true;
            }
            return false;
        }

        bool removeVertex(string vertex) {
            if (adjList.count(vertex) == 0) return false;
            for (auto otherVertex : adjList.at(vertex)){
                adjList.at(otherVertex).erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }
};

int main() {
    Graph* mygraph = new Graph();

    // Adding Vertices to the graph:
    mygraph->addVertex("A");
    mygraph->addVertex("B");
    mygraph->addVertex("C");
    mygraph->addVertex("D");

    // Adding edges to the vertices
    mygraph->addEdge("A","B");
    mygraph->addEdge("A","C");
    mygraph->addEdge("A","D");
    mygraph->addEdge("B","D");
    mygraph->addEdge("C","D");

    // Display the graph:
    cout << "Display Graph: " << endl;
    mygraph->printGraph();
    cout << "\n------------------------" << endl;
    cout << "\nRemoving edge: " << endl;

    // Removing edges from vertices:
    mygraph->removeEdge("A", "C");

    // Display the graph:
    mygraph->printGraph();
    cout << "\n------------------------" << endl;
    cout << "\nRemoving Vertex: " << endl;

    // Removing vertex from Graph:
    mygraph->removeVertex("D");

    // Display the graph:
    mygraph->printGraph();
}