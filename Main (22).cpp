#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int soluciones = 0;

bool seguro(int fila, int col, vector<int>& pos) {
    for (int i = 0; i < fila; i++)
        if (pos[i] == col || abs(pos[i] - col) == abs(i - fila))
            return false;
    return true;
}

void resolver(int fila, int n, vector<int>& pos) {
    if (fila == n) {
        soluciones++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (seguro(fila, col, pos)) {
            pos[fila] = col;
            resolver(fila + 1, n, pos);
        }
    }
}

int main() {
    int n = 4;
    vector<int> pos(n);
    resolver(0, n, pos);
    cout << "Número de soluciones para " << n << "-reinas: " << soluciones << endl;
}







