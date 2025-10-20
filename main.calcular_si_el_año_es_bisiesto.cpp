#include <iostream>

int main() {
int anio;

// 1. Solicitar al usuario que ingrese un año
std::cout << "Ingrese un año: ";
std::cin >> anio;

// 2. Verificar si el año es bisiesto
if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
std::cout << "El año " << anio << " es bisiesto." <<

std::endl;
} else {
std::cout << "El año " << anio << " no es bisiesto." <<

std::endl;
}

return 0;
}



