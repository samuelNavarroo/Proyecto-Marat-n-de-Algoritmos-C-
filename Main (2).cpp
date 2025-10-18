#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i=0; i<m; ++i){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,0});
    long long total=0;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        total+=w;
        for(auto [v,c]:adj[u]) if(!vis[v]) pq.push({c,v});
    }
    cout<<"Costo MST: "<<total<<"\n";
}



