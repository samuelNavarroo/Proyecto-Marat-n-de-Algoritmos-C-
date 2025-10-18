#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> grid;
vector<vector<int>> vis;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

void dfs(int x,int y){
    vis[x][y]=1;
    for(int k=0;k<4;++k){
        int nx=x+dx[k], ny=y+dy[k];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]&&grid[nx][ny]=='1')
            dfs(nx,ny);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;++i) cin>>grid[i];
    vis.assign(n,vector<int>(m,0));
    int islands=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!vis[i][j]&&grid[i][j]=='1'){
                dfs(i,j);
                islands++;
            }
    cout<<islands<<"\n";
}







