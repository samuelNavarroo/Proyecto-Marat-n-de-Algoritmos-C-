#include <bits/stdc++.h>
using namespace std;
int partitionRnd(vector<int>& a,int l,int r){
    int p=l+rand()%(r-l+1); swap(a[p],a[r]);
    int pivot=a[r], i=l;
    for(int j=l;j<r;++j) if(a[j]>pivot) swap(a[i++],a[j]);
    swap(a[i],a[r]); return i;
}
int quickselect(vector<int>& a,int l,int r,int k){
    if(l==r) return a[l];
    int p=partitionRnd(a,l,r), cnt = p-l+1;
    if(k==cnt) return a[p];
    if(k<cnt) return quickselect(a,l,p-1,k);
    return quickselect(a,p+1,r,k-cnt);
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    srand(time(0)); int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i)cin>>a[i];
    int k; cin>>k; cout<<quickselect(a,0,n-1,k)<<"\n";
}
