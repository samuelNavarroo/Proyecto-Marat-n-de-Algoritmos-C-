#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo(100, -1);

long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 45;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
}
