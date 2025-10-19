#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> numeros = {1, 2, 3, 4, 5};

    int suma = accumulate(numeros.begin(), numeros.end(), 0);
    cout << "Suma total: " << suma << endl;

    transform(numeros.begin(), numeros.end(), numeros.begin(),
              [](int x){ return x * 2; });
    cout << "Elementos duplicados: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    auto it = find_if(numeros.begin(), numeros.end(),
                      [](int x){ return x > 6; });
    if (it != numeros.end())
        cout << "Primer número mayor a 6: " << *it << endl;
}







