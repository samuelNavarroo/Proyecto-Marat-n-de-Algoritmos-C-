#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> state;
bool hasCycle = false;

void dfs(int u) {
    state[u] = 1; // en proceso
    for (int v : adj[u]) {
        if (state[v] == 0) dfs(v);
        else if (state[v] == 1) hasCycle = true;
    }
    state[u] = 2; // terminado
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    state.assign(n, 0);
    for (int i = 0; i < n; ++i)
        if (state[i] == 0) dfs(i);
    cout << (hasCycle ? "Sí hay ciclo" : "No hay ciclo") << "\n";
}




