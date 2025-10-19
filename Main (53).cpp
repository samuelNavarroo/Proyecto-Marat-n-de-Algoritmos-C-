#include <bits/stdc++.h>
using namespace std;
struct Student{ string name; int age; double gpa; };
int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<Student> v(n);
    for(int i=0;i<n;++i) cin>>v[i].name>>v[i].age>>v[i].gpa;
    sort(v.begin(),v.end(),[](const Student&a,const Student&b){
        if(a.gpa!=b.gpa) return a.gpa>b.gpa;
        if(a.age!=b.age) return a.age<b.age;
        return a.name<b.name;
    });
    for(auto &s:v) cout<<s.name<<" "<<s.age<<" "<<s.gpa<<"\n";
}
