#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int m,T; if(!(cin>>m>>T)) return 0; vector<int> coins(m); for(int i=0;i<m;++i)cin>>coins[i];
    vector<int> dp(T+1,INF); dp[0]=0;
    for(int c=1;c<=T;++c) for(int coin:coins) if(coin<=c) dp[c]=min(dp[c],dp[c-coin]+1);
    cout<<(dp[T]>=INF?-1:dp[T])<<"\n";
}
