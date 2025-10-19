#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
bool dfs(int s,int t, vector<vector<int>>& cap, vector<int>& parent){
    fill(parent.begin(),parent.end(),-1); parent[s]=-2;
    stack<pair<int,int>> st; st.push({s,INF});
    while(!st.empty()){
        auto [u,flow]=st.top(); st.pop();
        for(int v=0; v<n; ++v){
            if(parent[v]==-1 && cap[u][v]>0){
                parent[v]=u;
                int new_flow = min(flow, cap[u][v]);
                if(v==t) return true;
                st.push({v,new_flow});
            }
        }
    }
    return false;
}
int maxflow(int s,int t, vector<vector<int>>& cap){
    int flow=0; vector<int> parent(n);
    while(dfs(s,t,cap,parent)){
        int cur=t, bottleneck=INF;
        while(cur!=s){ bottleneck=min(bottleneck, cap[parent[cur]][cur]); cur=parent[cur]; }
        cur=t; while(cur!=s){ int p=parent[cur]; cap[p][cur]-=bottleneck; cap[cur][p]+=bottleneck; cur=p; }
        flow+=bottleneck;
    }
    return flow;
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> cap(n, vector<int>(n,0));
    for(int i=0;i<m;++i){int u,v,c;cin>>u>>v>>c; cap[u][v]+=c;}
    int s,t; cin>>s>>t; cout<<maxflow(s,t,cap)<<"\n";
}
