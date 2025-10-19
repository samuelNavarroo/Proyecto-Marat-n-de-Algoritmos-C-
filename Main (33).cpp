#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashMap {
    vector<list<pair<int, string>>> tabla;
    int tam;

public:
    HashMap(int s) : tam(s) { tabla.resize(s); }

    int hash(int clave) { return clave % tam; }

    void insertar(int clave, string valor) {
        int idx = hash(clave);
        for (auto& p : tabla[idx]) {
            if (p.first == clave) {
                p.second = valor;
                return;
            }
        }
        tabla[idx].push_back({clave, valor});
    }

    string buscar(int clave) {
        int idx = hash(clave);
        for (auto& p : tabla[idx])
            if (p.first == clave)
                return p.second;
        return "No encontrado";
    }

    void eliminar(int clave) {
        int idx = hash(clave);
        tabla[idx].remove_if([clave](auto& p) { return p.first == clave; });
    }

    void mostrar() {
        for (int i = 0; i < tam; ++i) {
            cout << i << ": ";
            for (auto& p : tabla[i])
                cout << "[" << p.first << " -> " << p.second << "] ";
            cout << endl;
        }
    }
};

int main() {
    HashMap mapa(7);
    mapa.insertar(10, "Juan");
    mapa.insertar(20, "Maria");
    mapa.insertar(17, "Pedro");
    mapa.insertar(7, "Ana");

    mapa.mostrar();

    cout << "Buscar clave 20: " << mapa.buscar(20) << endl;
    mapa.eliminar(10);
    cout << "Después de eliminar clave 10:\n";
    mapa.mostrar();
}

