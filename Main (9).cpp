#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void dijkstra(int n, int start, vector<vector<pair<int,int>>>& grafo) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, peso] : grafo[u]) {
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Distancia a nodo " << i << ": " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> grafo(n);

    grafo[0].push_back({1, 10});
    grafo[0].push_back({2, 3});
    grafo[1].push_back({2, 1});
    grafo[1].push_back({3, 2});
    grafo[2].push_back({1, 4});
    grafo[2].push_back({3, 8});
    grafo[2].push_back({4, 2});
    grafo[3].push_back({4, 7});
    grafo[4].push_back({3, 9});

    dijkstra(n, 0, grafo);
    return 0;
}












