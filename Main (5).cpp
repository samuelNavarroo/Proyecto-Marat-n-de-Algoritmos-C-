#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
bool cycle=false;

void dfs(int u,int p){
    vis[u]=1;
    for(int v:adj[u]){
        if(!vis[v]) dfs(v,u);
        else if(v!=p) cycle=true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    adj.assign(n,{});
    for(int i=0;i<m;++i){
        int u,v;cin>>u






