#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    cout << "Valor máximo de la mochila: " << knapsack(W, weights, values, values.size()) << endl;
    return 0;
}

