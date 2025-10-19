#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    pair<string, int> persona = {"Ana", 25};
    cout << persona.first << " tiene " << persona.second << " años\n";

    tuple<string, int, double> producto = {"Laptop", 5, 899.99};
    cout << get<0>(producto) << " - " << get<1>(producto)
         << " unidades - $" << get<2>(producto) << endl;

    return 0;
}








