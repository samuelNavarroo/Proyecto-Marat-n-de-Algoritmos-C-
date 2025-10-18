#include <bits/stdc++.h>
using namespace std;

pair<int,int> bfs(int start, vector<vector<int>>& adj){
    vector<int> dist(adj.size(),-1);
    queue<int> q;
    dist[start]=0;q.push(start);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:adj[u]) if(dist[v]==-1){
            dist[v]=dist[u]+1;q.push(v);
        }
    }
    int mx=0,node=start;
    for(int i=0;i<(int)dist.size();++i)
        if(dist[i]>mx){mx=dist[i];node=i;}
    return {node,mx};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto a=bfs(0,adj);
    auto b=bfs(a.first,adj);
    cout<<b.second<<"\n";
}










