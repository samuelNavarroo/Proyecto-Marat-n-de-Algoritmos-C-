#include <bits/stdc++.h>
using namespace std;
long long merge_count(vector<int>& a,int l,int m,int r){
    int i=l,j=m+1; long long cnt=0; vector<int> tmp;
    while(i<=m && j<=r){
        if(a[i]<=a[j]) tmp.push_back(a[i++]);
        else { tmp.push_back(a[j++]); cnt += (m - i + 1); }
    }
    while(i<=m) tmp.push_back(a[i++]); while(j<=r) tmp.push_back(a[j++]);
    for(int k=0;k<tmp.size();++k) a[l+k]=tmp[k];
    return cnt;
}
long long sort_count(vector<int>& a,int l,int r){
    if(l>=r) return 0;
    int m=(l+r)/2; long long cnt=sort_count(a,l,m)+sort_count(a,m+1,r);
    cnt += merge_count(a,l,m,r); return cnt;
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i)cin>>a[i];
    cout<<sort_count(a,0,n-1)<<"\n";
}
