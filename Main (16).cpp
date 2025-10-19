#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    pq.push(30);
    pq.push(10);
    pq.push(20);

    cout << "Elementos en orden creciente: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}







