#include <bits/stdc++.h>
using namespace std;
int binsearch(const vector<int>& a,int x){
    int l=0,r=(int)a.size()-1;
    while(l<=r){ int m=l+(r-l)/2; if(a[m]==x) return m; else if(a[m]<x) l=m+1; else r=m-1; }
    return -1;
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i) cin>>a[i];
    int x; cin>>x; cout<<binsearch(a,x)<<"\n";
}
