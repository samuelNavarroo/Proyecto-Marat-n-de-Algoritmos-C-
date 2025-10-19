#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Nodo {
    int x, y, g, h;
    bool operator>(const Nodo& o) const { return g + h > o.g + o.h; }
};

int heuristica(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int Astar(vector<vector<int>>& grid, pair<int,int> inicio, pair<int,int> meta) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> g(n, vector<int>(m, INT_MAX));
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> pq;

    g[inicio.first][inicio.second] = 0;
    pq.push({inicio.first, inicio.second, 0, heuristica(inicio.first, inicio.second, meta.first, meta.second)});

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    while (!pq.empty()) {
        auto [x, y, cost, h] = pq.top();
        pq.pop();

        if (x == meta.first && y == meta.second)
            return cost;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0) {
                int nuevoG = cost + 1;
                if (nuevoG < g[nx][ny]) {
                    g[nx][ny] = nuevoG;
                    pq.push({nx, ny, nuevoG, heuristica(nx, ny, meta.first, meta.second)});
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> mapa = {
        {0,0,0,0,0},
        {1,1,0,1,0},
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0}
    };
    cout << "Distancia mínima: " << Astar(mapa, {0,0}, {4,4}) << endl;
}









