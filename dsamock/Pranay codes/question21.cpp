#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(numVertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    vector<int> topologicalOrder() {
        vector<int> inDegree(numVertices, 0);

        for (int u = 0; u < numVertices; u++) {
            for (int v : adjList[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < numVertices; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> topologicalOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topologicalOrder.push_back(u);

            for (int v : adjList[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topologicalOrder;
    }

    void bfsTraversal(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph graph(numVertices);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int choice;
    cout << "Choose an operation:\n";
    cout << "1. Topological Ordering\n";
    cout << "2. BFS Traversal\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Topological Ordering: ";
        vector<int> result = graph.topologicalOrder();

        for (int vertex : result) {
            cout << vertex << " ";
        }
        cout << endl;
    } else if (choice == 2) {
        int startVertex;
        cout << "Enter the start vertex for BFS traversal: ";
        cin >> startVertex;

        cout << "BFS Traversal: ";
        graph.bfsTraversal(startVertex);
        cout << endl;
    } else {
        cout << "Invalid choice\n";
    }

    return 0;
}
