#include <bits/stdc++.h>
using namespace std;
int kthLargest(const vector<int>& a,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int x:a){
        if(pq.size()<k) pq.push(x);
        else if(x>pq.top()){ pq.pop(); pq.push(x); }
    }
    return pq.top();
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int>a(n); for(int i=0;i<n;++i)cin>>a[i];
    int k; cin>>k; cout<<kthLargest(a,k)<<"\n";
}
