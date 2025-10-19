#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> P;

int prim(int n, vector<vector<P>>& grafo) {
    vector<int> minEdge(n, INT_MAX);
    vector<bool> visitado(n, false);
    priority_queue<P, vector<P>, greater<P>> pq;

    minEdge[0] = 0;
    pq.push({0, 0});

    int total = 0;
    while (!pq.empty()) {
        int peso = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visitado[u]) continue;
        visitado[u] = true;
        total += peso;

        for (auto [w, v] : grafo[u])
            if (!visitado[v] && w < minEdge[v]) {
                minEdge[v] = w;
                pq.push({w, v});
            }
    }

    return total;
}

int main() {
    int n = 4;
    vector<vector<P>> grafo(n);
    grafo[0] = {{1,1}, {4,2}};
    grafo[1] = {{1,0}, {2,2}, {6,3}};
    grafo[2] = {{4,0}, {2,1}, {3,3}};
    grafo[3] = {{6,1}, {3,2}};

    cout << "Peso total del árbol mínimo: " << prim(n, grafo) << endl;
}
