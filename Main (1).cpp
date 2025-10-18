#include <bits/stdc++.h>
using namespace std;
const long long INF=1e15;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;++i){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int s;cin>>s;
    vector<int> indeg(n,0);
    for(auto &vec:adj) for(auto [v,_]:vec) indeg[v]++;
    queue<int> q;
    for(int i=0;i<n;++i) if(!indeg[i]) q.push(i);
    vector<int> topo;
    while(!q.empty()){
        int u=q.front();q.pop();
        topo.push_back(u);
        for(auto [v,_]:adj[u]) if(--indeg[v]==0) q.push(v);
    }
    vector<long long> dist(n,INF);
    dist[s]=0;
    for(int u:topo)
        if(dist[u]<INF)
            for(auto [v,w]:adj[u])
                dist[v]=min(dist[v],dist[u]+w);
    for(long long d:dist)
        cout<<(d==INF?"INF":to_string(d))<<" ";
    cout<<"\n";
}


