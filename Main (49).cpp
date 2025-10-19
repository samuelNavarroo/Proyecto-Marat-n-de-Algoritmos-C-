#include <bits/stdc++.h>
using namespace std;
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    string s,t; if(!(cin>>s>>t)) return 0;
    int n=s.size(), m=t.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i-1]==t[j-1]) cur[j]=prev[j-1]+1;
            else cur[j]=max(prev[j],cur[j-1]);
        }
        swap(prev,cur);
    }
    cout<<prev[m]<<"\n";
}
