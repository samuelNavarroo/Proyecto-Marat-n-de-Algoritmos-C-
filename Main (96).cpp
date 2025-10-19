#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    sort(arr.rbegin(), arr.rend());
    cout << "El " << k << "-ésimo elemento más grande es: " << arr[k-1] << endl;
    return 0;
}
