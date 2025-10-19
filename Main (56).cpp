#include <bits/stdc++.h>
using namespace std;
vector<int> counting_sort(const vector<int>& a,int maxv){
    vector<int> cnt(maxv+1,0);
    for(int x:a) ++cnt[x];
    vector<int> res; res.reserve(a.size());
    for(int v=0;v<=maxv;++v) while(cnt[v]--) res.push_back(v);
    return res;
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); int maxv=0;
    for(int i=0;i<n;++i){cin>>a[i]; maxv=max(maxv,a[i]);}
    auto s=counting_sort(a,maxv); for(int x:s) cout<<x<<" "; cout<<"\n";
}
