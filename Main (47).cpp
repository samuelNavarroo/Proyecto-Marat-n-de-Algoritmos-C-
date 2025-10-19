#include <bits/stdc++.h>
using namespace std;
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0; vector<vector<int>> adj(n);
    for(int i=0;i<m;++i){int u,v;cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);}
    int s,t; cin>>s>>t; vector<int> dist(n,-1), par(n,-1); queue<int>q;
    dist[s]=0; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:adj[u]) if(dist[v]==-1){ dist[v]=dist[u]+1; par[v]=u; q.push(v); }
    }
    if(dist[t]==-1){ cout<<"-1\n"; return 0;}
    cout<<dist[t]<<"\n";
    vector<int> path; for(int cur=t;cur!=-1;cur=par[cur]) path.push_back(cur);
    reverse(path.begin(),path.end()); for(int x:path) cout<<x<<" "; cout<<"\n";
}
