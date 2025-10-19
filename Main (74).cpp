#include <bits/stdc++.h>
using namespace std;
void mergeVec(vector<int>& a,int l,int m,int r){
    vector<int> L(a.begin()+l,a.begin()+m+1), R(a.begin()+m+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()) a[k++] = (L[i]<=R[j]?L[i++]:R[j++]);
    while(i<L.size()) a[k++]=L[i++]; while(j<R.size()) a[k++]=R[j++];
}
void mergesort(vector<int>& a,int l,int r){
    if(l>=r) return;
    int m=l+(r-l)/2; mergesort(a,l,m); mergesort(a,m+1,r); mergeVec(a,l,m,r);
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i) cin>>a[i];
    mergesort(a,0,n-1); for(int x:a) cout<<x<<" "; cout<<"\n";
}
