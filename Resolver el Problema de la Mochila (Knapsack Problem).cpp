C++
C++
#include <iostream>
#include <vector>
#include <algorithm> // Útil para verificar el estado de la búsqueda

/**
 * @brief Implementa el algoritmo de Búsqueda Binaria de forma iterativa.
 * * @param arr El vector de enteros *ordenado* en el que buscar.
 * @param target El valor a buscar.
 * @return El índice del target si se encuentra; -1 si no se encuentra.
 */
int binarySearch(const std::vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }

    int left = 0;
    int right = arr.size() - 1;

    // Continuar la búsqueda mientras el rango sea válido
    while (left <= right) {
        // Evita un posible desbordamiento de enteros (mejor que (left + right) / 2)
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            // Elemento encontrado
            return mid;
        } else if (arr[mid] < target) {
            // El target debe estar en la mitad superior (derecha)
            left = mid + 1;
        } else {
            // El target debe estar en la mitad inferior (izquierda)
            right = mid - 1;
        }
    }

    // El elemento no se encontró
    return -1;
}

void printResult(int target, int index) {
    if (index != -1) {
        std::cout << "El valor " << target << " fue encontrado en el índice: " << index << std::endl;
    } else {
        std::cout << "El valor " << target << " NO fue encontrado." << std::endl;
    }
}

int main() {
    // El vector DEBE estar ordenado para que la búsqueda binaria funcione.
    std::vector<int> sorted_data = {3, 9, 10, 27, 38, 43, 82};
    std::cout << "Vector de datos: [3, 9, 10, 27, 38, 43, 82]" << std::endl;

    // --- Caso 1: Elemento presente ---
    int target1 = 38;
    int index1 = binarySearch(sorted_data, target1);
    printResult(target1, index1); // Salida esperada: Índice 4

    std::cout << "----------------------------------" << std::endl;

    // --- Caso 2: Elemento presente (en los extremos) ---
    int target2 = 3;
    int index2 = binarySearch(sorted_data, target2);
    printResult(target2, index2); // Salida esperada: Índice 0

    std::cout << "----------------------------------" << std::endl;

    // --- Caso 3: Elemento no presente ---
    int target3 = 25;
    int index3 = binarySearch(sorted_data, target3);
    printResult(target3, index3); // Salida esperada: -1

    std::cout << "----------------------------------" << std::endl;

    // --- Caso 4: Vector vacío ---
    std::vector<int> empty_data = {};
    int target4 = 100;
    int index4 = binarySearch(empty_data, target4);
    std::cout << "Búsqueda en vector vacío: ";
    printResult(target4, index4); // Salida esperada: -1

    return 0;
}




