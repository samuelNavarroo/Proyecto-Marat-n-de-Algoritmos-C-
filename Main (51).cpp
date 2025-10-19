#include <bits/stdc++.h>
using namespace std;
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,W; if(!(cin>>n>>W)) return 0;
    vector<int>w(n),v(n); for(int i=0;i<n;++i) cin>>w[i]>>v[i];
    vector<int> dp(W+1,0);
    for(int i=0;i<n;++i) for(int c=w[i];c<=W;++c) dp[c]=max(dp[c],dp[c-w[i]]+v[i]);
    cout<<dp[W]<<"\n";
}