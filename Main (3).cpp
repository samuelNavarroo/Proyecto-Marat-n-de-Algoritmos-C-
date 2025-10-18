#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };
struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n,1) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;++i) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){return a.w<b.w;});
    DSU dsu(n);
    long long total=0;
    for(auto &e:edges)
        if(dsu.unite(e.u,e.v)) total+=e.w;
    cout<<"Costo del MST: "<<total<<"\n";
}



