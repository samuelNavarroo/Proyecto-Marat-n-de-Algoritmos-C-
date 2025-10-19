#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};

    cout << "Permutaciones de {1,2,3}:\n";
    sort(nums.begin(), nums.end());
    do {
        for (int x : nums) cout << x << " ";
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}







