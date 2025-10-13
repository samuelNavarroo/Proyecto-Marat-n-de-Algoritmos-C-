#include <iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    float saldo;

public:
    // Constructor
    CuentaBancaria(string nombre, float saldoInicial) {
        titular = nombre;
        saldo = saldoInicial;
    }

    // Depositar dinero
    void depositar(float monto) {
        if (monto <= 0) {
            cout << "❌ El monto debe ser mayor a 0.\n";
            return;
        }
        saldo += monto;
        cout << "✅ Se depositaron $" << monto << " correctamente.\n";
    }

    // Retirar dinero
    void retirar(float monto) {
        if (monto <= 0) {
            cout << "❌ El monto debe ser mayor a 0.\n";
            return;
        }
        if (monto > saldo) {
            cout << "❌ Saldo insuficiente. Operación cancelada.\n";
        } else {
            saldo -= monto;
            cout << "✅ Se retiraron $" << monto << " correctamente.\n";
        }
    }

    // Mostrar saldo
    void mostrarSaldo() const {
        cout << "💳 Titular: " << titular << endl;
        cout << "💰 Saldo actual: $" << saldo << endl;
    }
};

int main() {
    string nombre;
    float saldoInicial;

    cout << "=== 🏦 Sistema de Cuenta Bancaria 🏦 ===\n";
    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);
    cout << "Ingrese el saldo inicial: $";
    cin >> saldoInicial;

    CuentaBancaria cuenta(nombre, saldoInicial);

    int opcion;
    do {
        cout << "\n📋 MENU DE OPCIONES\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cuenta.mostrarSaldo();
            break;
        case 2: {
            float monto;
            cout << "Ingrese el monto a depositar: $";
            cin >> monto;
            cuenta.depositar(monto);
            break;
        }
        case 3: {
            float monto;
            cout << "Ingrese el monto a retirar: $";
            cin >> monto;
            cuenta.retirar(monto);
            break;
        }
        case 4:
            cout << "👋 Saliendo del sistema...\n";
            break;
        default:
            cout << "❌ Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

