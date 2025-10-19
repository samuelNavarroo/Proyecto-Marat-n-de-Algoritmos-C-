#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    string text = "hola mundo hola programacion mundo";
    map<string,int> freq;
    string word;
    stringstream ss(text);

    while (ss >> word) {
        freq[word]++;
    }

    for (auto& p : freq) {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}
