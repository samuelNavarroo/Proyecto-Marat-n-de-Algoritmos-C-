#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && DFS(neighbor, graph, visited, recStack))
            return true;
        else if (recStack[neighbor])
            return true;
    }
    recStack[node] = false;
    return false;
}

bool isCyclic(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false), recStack(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i] && DFS(i, graph, visited, recStack))
            return true;
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1},
        {2},
        {0},
        {}
    };
    cout << "El grafo tiene ciclo? " << (isCyclic(graph) ? "Sí" : "No") << endl;
    return 0;
}
