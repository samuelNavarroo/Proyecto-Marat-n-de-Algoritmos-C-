#include <bits/stdc++.h>
using namespace std;
struct SegTree{
    int n; vector<long long> st;
    SegTree(int n):n(n),st(4*n,0){}
    void build(int p,int l,int r,vector<int>&a){
        if(l==r){ st[p]=a[l]; return; }
        int m=(l+r)/2; build(p*2,l,m,a); build(p*2+1,m+1,r,a); st[p]=min(st[p*2],st[p*2+1]);
    }
    long long query(int p,int l,int r,int i,int j){
        if(i>r||j<l) return LLONG_MAX;
        if(i<=l&&r<=j) return st[p];
        int m=(l+r)/2; return min(query(p*2,l,m,i,j),query(p*2+1,m+1,r,i,j));
    }
    void update(int p,int l,int r,int idx,int val){
        if(l==r){ st[p]=val; return; }
        int m=(l+r)/2; if(idx<=m) update(p*2,l,m,idx,val); else update(p*2+1,m+1,r,idx,val);
        st[p]=min(st[p*2],st[p*2+1]);
    }
};
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i)cin>>a[i];
    SegTree st(n); st.build(1,0,n-1,a);
    int q; cin>>q; while(q--){ int type; cin>>type; if(type==1){int l,r;cin>>l>>r; cout<<st.query(1,0,n-1,l,r)<<"\n";} else {int idx,v;cin>>idx>>v; st.update(1,0,n-1,idx,v);} }
}

