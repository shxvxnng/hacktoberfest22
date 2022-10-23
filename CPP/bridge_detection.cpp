#include <bits/stdc++.h>

#define f(i, n) for (long long i = 0; i < n; i++)
#define pb push_back

typedef long long int ll;

using namespace std;

// EVERY SINGLE QUES TAKES YOU TOWARDS YOUR GOAL :) 
vector<ll> edge[1001];
ll vis[1001];
ll in[1001];
ll low[1001];
ll timer;

void dfs(ll node, ll parent)
{
    vis[node]= 1;
    low[node]= in[node] = timer;
    timer++;

    for(ll child:edge[node])
    {
        if(child == parent)
            continue;
        
        if(vis[child]==1)
        {
            low[node] = min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);


            if(low[child] > in[node])
            {
                cout<<node<<"->"<<child<<" is a bridge"<<endl;
            }

            low[node] = min(low[node],low[child]);
        }
        
    }
}


int main()
{


        ll n,m;
        cin>>n>>m;

        while(m--)
        {
            ll a,b;
            cin>>a>>b;
            edge[a].pb(b);
            edge[b].pb(a);
        }

        dfs(1,-1);
        
}
