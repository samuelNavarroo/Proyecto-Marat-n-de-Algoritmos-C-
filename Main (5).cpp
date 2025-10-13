#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese tamaño del conjunto: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tamaño inválido." << endl;
        return 1;
    }

    int numeros[n];
    cout << "Ingrese número 1: ";
    cin >> numeros[0];
    int mayor = numeros[0];

    for (int i = 1; i < n; ++i) {
        cout << "Ingrese número " << i+1 << ": ";
        cin >> numeros[i];
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    cout << "El número mayor es: " << mayor << endl;

    return 0;
}
