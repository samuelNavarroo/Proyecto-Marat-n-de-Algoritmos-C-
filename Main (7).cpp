#include <iostream>
#include <vector>

int knapsack(int capacidad, const std::vector<int>& pesos, const std::vector<int>& valores, int n) {
    // Crear la tabla DP
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacidad + 1, 0));

    // Llenar la tabla DP
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacidad; ++j) {
            if (pesos[i - 1] <= j) {
                // Si el objeto cabe en la mochila, decidir entre incluirlo o no
                dp[i][j] = std::max(dp[i - 1][j], valores[i - 1] + dp[i - 1][j - pesos[i - 1]]);
            } else {
                // Si no cabe, no incluirlo
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacidad];  // El valor máximo que se puede obtener
}

int main() {
    int capacidad;
    int n;

    // Leer la capacidad de la mochila y el número de objetos
    std::cout << "Ingresa la capacidad de la mochila: ";
    std::cin >> capacidad;
    std::cout << "Ingresa el número de objetos: ";
    std::cin >> n;

    std::vector<int> pesos(n), valores(n);

    // Leer los pesos y valores de los objetos
    std::cout << "Ingresa los pesos de los objetos:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> pesos[i];
    }

    std::cout << "Ingresa los valores de los objetos:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> valores[i];
    }

    // Resolver el problema de la mochila
    int resultado = knapsack(capacidad, pesos, valores, n);
    
    // Mostrar el resultado
    std::cout << "El valor máximo que se puede obtener es: " << resultado << std::endl;

    return 0;
}

