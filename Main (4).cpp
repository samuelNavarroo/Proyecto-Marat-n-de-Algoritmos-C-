#include <iostream>
using namespace std;

int main() {
    double saldo = 1000.0;
    int opcion;
    double retiro;

    cout << "Bienvenido al cajero automático\n";

    do {
        cout << "\nMenú:\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Su saldo actual es: $" << saldo << endl;
                break;
            case 2:
                cout << "Ingrese el monto a retirar: ";
                cin >> retiro;

                if (retiro <= 0) {
                    cout << "Monto inválido. Debe ser mayor que cero." << endl;
                } else if (retiro > saldo) {
                    cout << "Saldo insuficiente para realizar el retiro." << endl;
                } else {
                    saldo -= retiro;
                    cout << "Retiro exitoso. Su nuevo saldo es: $" << saldo << endl;
                }
                break;
            case 3:
                cout << "Gracias por usar el cajero automático. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción del menú." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
