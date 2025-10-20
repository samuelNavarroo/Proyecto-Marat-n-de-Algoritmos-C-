#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> nums = {1,2,2,3,4,4,5};
    set<int> unique(nums.begin(), nums.end());
    cout << "Número de elementos únicos: " << unique.size() << endl;
    return 0;
}
