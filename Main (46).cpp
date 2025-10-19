#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj; vector<int> color; bool hasCycle=false;
void dfs(int u){ color[u]=1; for(int v:adj[u]){ if(color[v]==0) dfs(v); else if(color[v]==1) hasCycle=true; } color[u]=2; }
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0; adj.assign(n,{}); for(int i=0;i<m;++i){int u,v;cin>>u>>v;adj[u].push_back(v);}
    color.assign(n,0); for(int i=0;i<n;++i) if(color[i]==0) dfs(i);
    cout<<(hasCycle?1:0)<<"\n";
}
