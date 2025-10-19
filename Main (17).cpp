#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros = {1, 3, 5, 3, 1, 3, 7};
    unordered_map<int, int> frecuencia;

    for (int num : numeros)
        frecuencia[num]++;

    for (auto& par : frecuencia)
        cout << par.first << " aparece " << par.second << " veces\n";

    return 0;
}








