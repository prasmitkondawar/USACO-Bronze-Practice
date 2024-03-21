#include <iostream> 
#include <vector> 
#include <queue>
#define ll long long int
#define f(i,n) for(ll i=0;i<n;i++)
#define pb push_back
using namespace std;

vector <ll> v[100005];
vector <bool> vis(100005,false);
vector <ll>   par(100005);
vector <ll> dis(100005);
void dfs(ll node)
{
  vis[node]=true;
  // Let's go through all the neighbours of node
  for(auto z:v[node])
  {
      if(!vis[z])
      {
         par[z]=node;
         dfs(z);
      }
  }
}
void bfs(ll source)
{
    queue <int> q;
    q.push(source);
    vis[source]=true;
    dis[source]=0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<"distance of "<<node<<' '<<"from "<<source<<" is "<<dis[node]<<"\n";
        for(auto z:v[node])
        {
            if(!vis[z])
            {
                vis[z]=true;
                dis[z]=1+dis[node];
                q.push(z);
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    f(i,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int cc=0;
    // for(int i=1;i<=n;i++)
    // {
    //     if(!vis[i]) 
    //     {
    //         par[i]=-1;
    //         dfs(i);
    //         cc++;
    //     }
    // }
     for(int i=1;i<=n;i++)
    {
        if(!vis[i]) 
        {
            bfs(i);
            cc++;
        }
    }
    cout<<"Connected Components "<<cc<<"\n";
}