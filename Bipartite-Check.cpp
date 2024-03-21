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
bool bipartite=true;
void dfs(ll node)
{
  vis[node]=true;
  // Let's go through all the neighbours of node
  for(auto z:v[node])
  {
      if(!vis[z])
      {
         colour[z]=1-colour[node];
         dfs(z);
      }
      else if(colour[z]==colour[node])
      {
         bipartite=false;
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
            dfs(i);
        }
    }
    if(bipartite)
    {
        cout<<"The graph is bipartite\n";
        cout<<"Set0 : ";
        for(ll i=1;i<=n;i++) {
            if(colour[i]==0) cout<<i<<' ';
        }
        cout<<"\n";
        cout<<"Set1 : ";
        for(ll i=1;i<=n;i++) {
            if(colour[i]==1) cout<<i<<' ';
        }
    }
    else cout<<"Not Bipartite";
}