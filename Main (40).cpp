#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> a={1,3,5,3,1,3,7}; unordered_map<int,int> f;
    for(int x:a) ++f[x];
    for(auto &p:f) cout<<p.first<<" -> "<<p.second<<"\n";
}

