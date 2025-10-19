#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(10); // duplicado, no se inserta

    cout << "Elementos en el set: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    int buscar = 20;
    cout << buscar << (s.count(buscar) ? " encontrado" : " no encontrado") << endl;

    return 0;
}

