#include <bits/stdc++.h>
using namespace std; using ll=long long; const ll INF=1e18;
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0; vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;++i){int u,v,w;cin>>u>>v>>w; adj[u].push_back({v,w});}
    int s; cin>>s; vector<ll> dist(n,INF); dist[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq; pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop(); if(d!=dist[u]) continue;
        for(auto [v,w]:adj[u]) if(dist[v]>dist[u]+w){ dist[v]=dist[u]+w; pq.push({dist[v],v}); }
    }
    for(int i=0;i<n;++i) cout<<(dist[i]==INF?"INF":to_string(dist[i]))<<" ";
    cout<<"\n";
}
