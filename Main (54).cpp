#include <bits/stdc++.h>
using namespace std;
int firstOcc(const vector<int>& a,int x){
    int l=0,r=a.size()-1,ans=-1;
    while(l<=r){int m=(l+r)/2; if(a[m]>=x){ if(a[m]==x) ans=m; r=m-1;} else l=m+1;}
    return ans;
}
int lastOcc(const vector<int>& a,int x){
    int l=0,r=a.size()-1,ans=-1;
    while(l<=r){int m=(l+r)/2; if(a[m]<=x){ if(a[m]==x) ans=m; l=m+1;} else r=m-1;}
    return ans;
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i)cin>>a[i];
    int x; cin>>x; cout<<firstOcc(a,x)<<" "<<lastOcc(a,x)<<"\n";
}
