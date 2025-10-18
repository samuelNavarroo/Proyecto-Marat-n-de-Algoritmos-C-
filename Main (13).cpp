Ejercicio 16: Problema de la Mochila 0/1 (Knapsack Problem)
🔹 Análisis del Problema

Descripción:
Dado un conjunto de objetos con pesos y valores, y una capacidad máxima de mochila, encontrar el valor máximo que puede obtenerse sin exceder el peso.

Entradas:

Número de objetos n.

Vectores pesos[], valores[].

Capacidad máxima W.

Salida:

Valor máximo posible.

🔹 Diseño de la Solución

Se usa programación dinámica (DP) con una matriz dp[i][w] que representa el valor máximo al considerar los primeros i objetos con capacidad w.

🔹 Código Fuente
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& pesos, vector<int>& valores, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (pesos[i - 1] <= w)
                dp[i][w] = max(valores[i - 1] + dp[i - 1][w - pesos[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> valores = {60, 100, 120};
    vector<int> pesos = {10, 20, 30};
    int W = 50;
    cout << "Valor máximo: " << knapsack(W, pesos, valores, valores.size()) << endl;
    return 0;
}

🔹 Salida esperada:
Valor máximo: 220






