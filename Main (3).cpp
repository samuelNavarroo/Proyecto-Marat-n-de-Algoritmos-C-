#include <iostream>
using namespace std;
int main() {
    double radio, area;
    const double PI = 3.1416;

    cout << "Ingrese el radio del círculo: ";
    cin >> radio;

    if (radio < 0) {
        cout << "El radio no puede ser negativo." << endl;
        return 1;
    }

    area = PI * radio * radio;
    cout << "El área del círculo es: " << area << endl;

    return 0;
}


