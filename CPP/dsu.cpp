#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int par[N];
int sz[N]; // size
void make(int v){
    par[v] = v;
    sz[v] = 1;
}
int find(int v){
    if(v==par[v])return v;

    return par[v] = find(par[v]); // path compression 
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        // union by size
        if(sz[a]<sz[b])
            swap(a,b);

        par[b] = a;
        sz[a]+=sz[b];
    }
}
int main(){
    // DSU to find connected componenet
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++)make(i);

    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_comp = 0;
    for(int i = 1;i<=n;i++){
        if(find(i)==i)connected_comp++;    
    }
    cout<<connected_comp;



}
