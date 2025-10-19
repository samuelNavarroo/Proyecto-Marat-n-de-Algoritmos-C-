#include <iostream>
#include <vector>
using namespace std;

int buscarInicio(vector<int>& v, int x) {
    int izq = 0, der = v.size() - 1, res = -1;
    while (izq <= der) {
        int mid = (izq + der) / 2;
        if (v[mid] == x) {
            res = mid;
            der = mid - 1;
        } else if (v[mid] < x)
            izq = mid + 1;
        else
            der = mid - 1;
    }
    return res;
}

int buscarFin(vector<int>& v, int x) {
    int izq = 0, der = v.size() - 1, res = -1;
    while (izq <= der) {
        int mid = (izq + der) / 2;
        if (v[mid] == x) {
            res = mid;
            izq = mid + 1;
        } else if (v[mid] < x)
            izq = mid + 1;
        else
            der = mid - 1;
    }
    return res;
}

int main() {
    vector<int> arr = {1,2,2,2,3,4,5};
    int x = 2;
    cout << "Primer índice: " << buscarInicio(arr, x) << endl;
    cout << "Último índice: " << buscarFin(arr, x) << endl;
}
