#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double fitness(double x) { return x * sin(10 * M_PI * x) + 1; }

double random_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

int main() {
    srand(time(0));
    const int POP = 50, GENERACIONES = 100;
    vector<double> poblacion(POP);
    for (auto& x : poblacion) x = random_double(0, 1);

    for (int gen = 0; gen < GENERACIONES; ++gen) {
        vector<double> nueva;
        for (int i = 0; i < POP; ++i) {
            double padre1 = poblacion[rand() % POP];
            double padre2 = poblacion[rand() % POP];
            double hijo = (padre1 + padre2) / 2 + random_double(-0.05, 0.05);
            hijo = max(0.0, min(1.0, hijo));
            nueva.push_back(hijo);
        }
        poblacion = nueva;
    }

    double mejor = poblacion[0];
    for (auto x : poblacion)
        if (fitness(x) > fitness(mejor)) mejor = x;

    cout << "Máximo estimado en x=" << mejor << " con f(x)=" << fitness(mejor) << endl;
}

