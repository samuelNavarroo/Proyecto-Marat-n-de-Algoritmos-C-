#include <iostream>
using namespace std;
#include <iostream>
#include <map>
#include <sstream>
#include <cctype>

void contarFrecuenciaPalabras(const std::string& texto) {
    std::map<std::string, int> frecuencia;
    std::stringstream ss(texto);
    std::string palabra;

    // Leer cada palabra del texto
    while (ss >> palabra) {
        // Convertir la palabra a minúsculas
        for (char& c : palabra) {
            c = std::tolower(c); // Convertir a minúscula
        }
        // Incrementar la frecuencia de la palabra
        frecuencia[palabra]++;
    }

    // Mostrar las palabras y su frecuencia
    std::cout << "Frecuencia de palabras:\n";
    for (const auto& par : frecuencia) {
        std::cout << par.first << ": " << par.second << std::endl;
    }
}

int main() {
    std::string texto;
    
    // Leer todo el texto de la entrada estándar
    std::cout << "Ingresa un texto (fin con Enter vacío):\n";
    std::getline(std::cin, texto);

    contarFrecuenciaPalabras(texto);

    return 0;
}¨
