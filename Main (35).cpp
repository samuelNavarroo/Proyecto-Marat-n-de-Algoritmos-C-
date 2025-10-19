#include <bits/stdc++.h>
using namespace std;
int partitionRnd(vector<int>& a,int l,int r){
    int p = l + rand()%(r-l+1);
    swap(a[p],a[r]);
    int pivot=a[r], i=l-1;
    for(int j=l;j<r;++j) if(a[j]<=pivot) swap(a[++i],a[j]);
    swap(a[i+1],a[r]); return i+1;
}
void quicksort(vector<int>& a,int l,int r){
    if(l<r){ int p=partitionRnd(a,l,r); quicksort(a,l,p-1); quicksort(a,p+1,r); }
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    srand(time(0));
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n); for(int i=0;i<n;++i) cin>>a[i];
    quicksort(a,0,n-1);
    for(int x:a) cout<<x<<" "; cout<<"\n";
}
