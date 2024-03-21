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
vector <ll> colour(100005);
bool cycle=false;
void dfs(ll node,ll par)
{
  vis[node]=true;
  // Let's go through all the neighbours of node
  for(auto z:v[node])
  {
      if(!vis[z])
      {
          dfs(z,node);
      }
      else
      {
          if(z!=par)
          {
             cycle = true;
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
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) 
        {  
            colour[i]=0;
            dfs(i,-1);
        }
    }
    if(cycle) cout<<"Cyclic Graph";
    else      cout<<"Acyclic Graph";
}