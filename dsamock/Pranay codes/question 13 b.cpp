#include <iostream>
#include <vector>
#include <stack>
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

    void topologicalOrderDFS(int v, vector<bool>& visited, stack<int>& result) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                topologicalOrderDFS(neighbor, visited, result);
            }
        }

        result.push(v);
    }

    vector<int> topologicalOrder() {
        vector<bool> visited(numVertices, false);
        stack<int> result;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                topologicalOrderDFS(i, visited, result);
            }
        }

        vector<int> topologicalOrder;
        while (!result.empty()) {
            topologicalOrder.push_back(result.top());
            result.pop();
        }

        return topologicalOrder;
    }

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void dfsTraversal() {
        vector<bool> visited(numVertices, false);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }
    }
};

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    // Adding edges
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    // Case 1: Topological Ordering
    cout << "Topological Ordering: ";
    vector<int> result = graph.topologicalOrder();

    for (int vertex : result) {
        cout << vertex << " ";
    }

    cout << endl;

    // Case 2: DFS Traversal
    cout << "DFS Traversal: ";
    graph.dfsTraversal();
    cout << endl;

    return 0;
}
