#include <bits/stdc++.h>
using namespace std;
struct BIT{ int n; vector<long long> bit; BIT(int n):n(n),bit(n+1,0){}; void add(int idx,long long val){ for(++idx; idx<=n; idx+=idx&-idx) bit[idx]+=val;} long long sum(int idx){ long long r=0; for(++idx; idx>0; idx-=idx&-idx) r+=bit[idx]; return r; } long long rangeSum(int l,int r){ if(r<l) return 0; return sum(r)-(l?sum(l-1):0);} };
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; BIT bit(n); for(int i=0;i<n;++i){int x;cin>>x; bit.add(i,x);}
    int q; cin>>q; while(q--){int type;cin>>type; if(type==1){int idx,v;cin>>idx>>v; bit.add(idx,v);} else {int l,r;cin>>l>>r; cout<<bit.rangeSum(l,r)<<"\n";}}
}
