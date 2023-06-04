#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;

class Graph {
    int vertices;
    int adjMatrix[MAX][MAX];

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void DFS(int startVertex, bool visited[]) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[startVertex][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void BFS(int startVertex, bool visited[]) {
        queue<int> q;
        visited[startVertex] = true;
        cout << startVertex << " ";
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    cout << i << " ";
                    q.push(i);
                }
            }
        }
    }

    bool isConnected() {
        bool visited[MAX] = { false };
        DFS(0, visited);

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    int countConnectedComponents() {
        int count = 0;
        bool visited[MAX] = { false };

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                DFS(i, visited);
                count++;
            }
        }

        return count;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    cout << "Depth First Traversal (DFS): ";
    bool visited[MAX] = { false };
    graph.DFS(0, visited);
    cout << endl;

    cout << "Breadth First Traversal (BFS): ";
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    graph.BFS(0, visited);
    cout << endl;

    if (graph.isConnected()) {
        cout << "The graph is connected." << endl;
    }
    else {
        cout << "The graph is not connected." << endl;
        int components = graph.countConnectedComponents();
        cout << "Number of connected components: " << components << endl;
    }

    return 0;
}
