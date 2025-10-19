#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 5;
    int index = binarySearch(arr, target);
    if (index != -1) cout << "Elemento encontrado en índice: " << index << endl;
    else cout << "Elemento no encontrado" << endl;
    return 0;
}
