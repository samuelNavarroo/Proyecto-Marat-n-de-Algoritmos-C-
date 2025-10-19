#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
using namespace std;

void sumaParcial(vector<int>& arr, int inicio, int fin, long long& resultado) {
    resultado = accumulate(arr.begin() + inicio, arr.begin() + fin, 0LL);
}

int main() {
    vector<int> datos(1000000);
    iota(datos.begin(), datos.end(), 1);

    long long suma1 = 0, suma2 = 0;

    thread t1(sumaParcial, ref(datos), 0, datos.size() / 2, ref(suma1));
    thread t2(sumaParcial, ref(datos), datos.size() / 2, datos.size(), ref(suma2));

    t1.join();
    t2.join();

    cout << "Suma total = " << (suma1 + suma2) << endl;
}


