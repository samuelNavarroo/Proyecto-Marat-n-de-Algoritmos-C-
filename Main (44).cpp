#include <bits/stdc++.h>
using namespace std; using ll=long long; const ll INF=1e18;
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0; vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;++i){int u,v,w;cin>>u>>v>>w; edges.emplace_back(u,v,w);}
    int s; cin>>s; vector<ll> dist(n,INF); dist[s]=0;
    for(int it=0; it<n-1; ++it){
        bool ch=false;
        for(auto &e:edges){int u,v,w; tie(u,v,w)=e; if(dist[u]!=INF && dist[v]>dist[u]+w){ dist[v]=dist[u]+w; ch=true; }}
        if(!ch) break;
    }
    for(auto &e:edges){int u,v,w; tie(u,v,w)=e; if(dist[u]!=INF && dist[v]>dist[u]+w){ cout<<"NEGATIVE CYCLE\n"; return 0; }}
    for(auto d:dist) cout<<(d==INF?"INF":to_string(d))<<" "; cout<<"\n";
}
