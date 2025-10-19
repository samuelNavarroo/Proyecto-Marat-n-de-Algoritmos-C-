#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> numeros = {5, 3, 8, 3, 9, 3};

    cout << "Elementos ordenados (con duplicados): ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    cout << "Cantidad de 3s: " << numeros.count(3) << endl;
    return 0;
}








