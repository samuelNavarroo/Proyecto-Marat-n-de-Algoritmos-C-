#include <iostream>
#include <vector>
using namespace std;

bool dfs(int nodo, int padre, vector<vector<int>>& grafo, vector<bool>& visitado) {
    visitado[nodo] = true;
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            if (dfs(vecino, nodo, grafo, visitado))
                return true;
        } else if (vecino != padre) {
            return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> grafo(n);
    grafo[0] = {1,2};
    grafo[1] = {0,2};
    grafo[2] = {0,1,3};
    grafo[3] = {2};

    vector<bool> visitado(n,false);
    bool ciclo = false;
    for (int i = 0; i < n; i++)
        if (!visitado[i] && dfs(i, -1, grafo, visitado))
            ciclo = true;

    cout << (ciclo ? "Ciclo detectado" : "Sin ciclo") << endl;
}










