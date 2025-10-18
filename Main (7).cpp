#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int u){
    vis[u]=1;
    for(int v:adj[u])
        if(!vis[v]) dfs(v);
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
    vis.assign(n,0);
    int comps=0;
    for(int i=0;i<n;++i)
        if(!vis[i]){ dfs(i); comps++; }
    cout<<comps<<"\n";
}









