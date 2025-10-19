#include <bits/stdc++.h>
using namespace std;
vector<int> mergeArrays(const vector<int>& A,const vector<int>& B){
    int i=0,j=0; vector<int> C; C.reserve(A.size()+B.size());
    while(i<A.size() && j<B.size()) C.push_back(A[i]<=B[j]?A[i++]:B[j++]);
    while(i<A.size()) C.push_back(A[i++]); while(j<B.size()) C.push_back(B[j++]);
    return C;
}
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n)) return 0; vector<int>A(n); for(int i=0;i<n;++i)cin>>A[i];
    cin>>m; vector<int>B(m); for(int i=0;i<m;++i)cin>>B[i];
    for(int x:mergeArrays(A,B)) cout<<x<<" "; cout<<"\n";
}
