#include <iostream>
#include <vector>
#include <queue>
#include <functional> // Necesario para std::greater

/**
 * @brief Encuentra el k-ésimo elemento más grande de un vector usando un Min Heap de tamaño k.
 * * @param nums El vector de números desordenados.
 * @param k El rango del elemento a buscar (k=1 es el más grande).
 * @return El valor del k-ésimo elemento más grande.
 */
int findKthLargest(const std::vector<int>& nums, int k) {
    if (k <= 0 || k > nums.size()) {
        throw std::out_of_range("El valor de k está fuera del rango válido para el vector.");
    }
    
    // 1. Inicializar un Min Heap (el elemento más pequeño está en la cima).
    // std::greater<int> invierte el orden natural, creando un Min Heap.
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    // 2. Iterar sobre todos los elementos
    for (int num : nums) {
        // 3. Insertar el elemento actual
        min_heap.push(num);
        
        // 4. Si el tamaño excede k, eliminar el elemento más pequeño (la raíz del Min Heap)
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // 5. El elemento en la cima es el k-ésimo más grande
    return min_heap.top();
}

int main() {
    std::vector<int> data = {3, 2, 1, 5, 6, 4};
    int k1 = 2; // Segundo más grande

    std::cout << "Vector de datos: [3, 2, 1, 5, 6, 4]" << std::endl;
    
    // --- Caso 1: k=2 ---
    try {
        int result1 = findKthLargest(data, k1);
        std::cout << "El " << k1 << "-ésimo elemento más grande es: " << result1 << " (Debe ser 5)" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----------------------------------" << std::endl;

    // --- Caso 2: k=4 ---
    std::vector<int> data2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4; // Cuarto más grande
    std::cout << "Vector de datos: [3, 2, 3, 1, 2, 4, 5, 5, 6]" << std::endl;
    
    try {
        int result2 = findKthLargest(data2, k2);
        std::cout << "El " << k2 << "-ésimo elemento más grande es: " << result2 << " (Debe ser 4)" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}




