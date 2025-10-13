#include <iostream>
using namespace std;
#include <iostream>
#include <vector>

// Función para realizar el particionado
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Tomamos el último elemento como pivote
    int i = low - 1;        // Índice del menor elemento

    // Recorremos el arreglo y reordenamos
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);  // Intercambiamos los elementos
        }
    }
    std::swap(arr[i + 1], arr[high]);  // Colocamos el pivote en su posición final
    return i + 1;
}

// Función recursiva que ordena el arreglo usando Quicksort
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Encuentra la posición del pivote

        // Ordenamos recursivamente las sublistas a la izquierda y derecha del pivote
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};

    std::cout << "Arreglo original: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quicksort(arr, 0, arr.size() - 1);

    std::cout << "Arreglo ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
