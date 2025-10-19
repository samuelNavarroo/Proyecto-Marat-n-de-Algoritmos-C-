#include <iostream>
#include <vector>
using namespace std;

int mochila(int W, vector<int>& pesos, vector<int>& valores, int n) {
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
    cout << "Valor máximo posible: " << mochila(W, pesos, valores, valores.size()) << endl;
}
