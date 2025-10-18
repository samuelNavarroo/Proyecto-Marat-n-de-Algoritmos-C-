#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string texto = "hola mundo hola programador mundo cplusplus";
    map<string, int> frecuencia;
    stringstream ss(texto);
    string palabra;

    while (ss >> palabra)
        frecuencia[palabra]++;

    for (auto& par : frecuencia)
        cout << par.first << " -> " << par.second << endl;
}











