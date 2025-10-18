#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> disc, low, vis;
int timer=0;

void dfs(int u,int p){
    vis[u]=1;
    disc[u]=low[u]=++timer;
    for(int v:adj[u]){
        if(v==p) continue;
        if(!vis[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
                cout<<"Puente: "<<u<<" - "<<v<<"\n";
        } else low[u]=min(low[u],disc[v]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    adj.assign(n,{});
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    disc.assign(n,0); low.assign(n,0); vis.assign(n,0);
    for(int i=0;i<n;++i) if(!vis[i]) dfs(i,-1);
}
