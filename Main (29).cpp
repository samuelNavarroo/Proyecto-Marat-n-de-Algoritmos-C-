#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> P; // (distancia, nodo)

void dijkstra(int inicio, vector<vector<P>>& grafo) {
    int n = grafo.size();
    vector<int> dist(n, INT_MAX);
    dist[inicio] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, inicio});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [peso, v] : grafo[u]) {
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Distancias desde el nodo " << inicio << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Nodo " << i << ": " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<P>> grafo(n);
    grafo[0] = {{10,1}, {3,2}};
    grafo[1] = {{1,2}, {2,3}};
    grafo[2] = {{4,1}, {8,3}, {2,4}};
    grafo[3] = {{7,4}};
    grafo[4] = {};

    dijkstra(0, grafo);
}

