#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
    vector<int> distance(graph.size(), -1);
    queue<int> q;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < distance.size(); i++)
        cout << "Distancia a nodo " << i << ": " << distance[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    BFS(graph, 0);
    return 0;
}

