#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <deque>
#include <iomanip>
#include <tuple>
#include <functional>
#include <limits>
#include <fstream>
#define ll         long long int
#define umap       unordered_map
#define mod        1000000007ll
#define pb         push_back
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()
#define MN(a,b,c)  min(a,min(b,c))
#define MX(a,b,c)  max(a,max(b,c))
#define pr1         pair<ll,ll>
#define F          first
#define S          second
#define mP         make_pair
#define f(i,n)     for(ll i=0;i<n;i++)
#define f1(i,x,y)  for(ll i=x;i<=y;i++)
#define f2(i,x,y)  for(ll i=x;i>=y;i--)
#define yes        cout<<"Yes"<<"\n"
#define no         cout<<"No"<<"\n"
#define modsum(a,b)  ((a%mod)+(b%mod))%mod
#define modpro(a,b)  ((a%mod)*(b%mod))%mod
#define moddif(a,b)  ((a%mod)-(b%mod)+mod)%mod
#define modsumt(a,b,c) modsum(a,modsum(b,c))
// Remove macro of endl in interactive task
// in case of no errors check macros and functions again
//__builtin_popcount(x)
//__builtin_parity(x)   =(number of set bits)%2
//__builtin_clz(x)      to count the number of leading  zeroes 
//__builtin_ctz(x)      to count the number of trailing zeroes 
//__gcd(a,b)
// Binary Search 
// TO AVOID GETTING INFINITE LOOP
// [l,r]   -> [l,mid-1] or  [mid+1,r]
//std::cout << std::fixed; std::cout << std::setprecision(12); std::cout << z ;
using namespace std;
ll modularExponentiation(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=modpro(result,x);
        x=modpro(x,x);
        n=n/2;
    }
    return result;
}
ll binaryExponentiation(ll x,ll n)
{
    ll result=1.0;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}
ll pow1(ll x,ll y)
{
    ll z=1;
    while(y--){z=z*x;}
    return z;
}
bool isprime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
// Returns n^(-1) mod p 
ll  modInverse(ll n, ll p) 
{ 
    return modularExponentiation(n, p - 2, p); 
} 
ll check(ll x,ll y)
{
    ll z=1;
    ll ans=0;
    while(z<x){ans++;z*=y;}
    return ans;
}
ll count11bits(ll n)
{
    ll x=0;
    while(n>0)
    {
        x++;
        n=(n&(n-1));
    }
    return x;
}
ll get_gcd(ll a,ll b)
{
   if(a<b) swap(a,b);
   if(a==b || b==0) return a;
   else     return get_gcd(b,a%b);
}
/*
 BFS
 vector <ll> visited(n+1,0);
 vector <ll>  parent(n+1);
 vector <ll>   level(n+1);
 queue <ll> q;
 q.push(1);
 visited[1]=1;
 level[1]=0;
 while(!q.empty())
 {
      ll node = q.front();
      q.pop();
      for(auto z : v[node])
      {
         if(!visited[z])
         {
            level[z]=1+level[node];
            parent[z]=node;
            visited[z]=1;
            q.push(z);
         }
      }
 }
 vector <pair<ll,ll>> lev_node(n);
 f(i,n) lev_node[i]={level[i+1],i+1};
*/
// DSU
/*
ll parent[200005];
ll depth[200005];
ll sz[200005];
void set_values(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        parent[i]=i;
        depth[i]=0;
        sz[i]=1;
    }
}
 // Path Compression
ll find_Parent(ll node)
{
    if(node==parent[node])
    {
       return node;
    } 
    return parent[node] = find_Parent(parent[node]);
}
void Union(ll u,ll v)
{
    u=find_Parent(u);
    v=find_Parent(v);
    if(depth[u]<depth[v])
    {
        parent[u] = v;
        sz[v]+=sz[u];
    }
    else if(depth[v]<depth[u])
    {
        parent[v] = u;
        sz[u]+=sz[v];
    }
    else 
    {
        parent[v] = u;
        sz[u]+=sz[v];
        // since Depth of u and v are same depth of u will increase by 1
        depth[u]++;
    }
}*/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;cin>>n;
  vector <ll> a(n);
  f(i,n) cin>>a[i];
  sort(all(a));
  ll q;cin>>q;
  while(q--)
  {
    ll x;cin>>x;
    // lower bound of x = smallest number y in thr array such that y>=x 
    // upper bound of x = smallest number y in thr array such that y>x
    ll ans=-1;
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(a[mid]>=x)
        {
            ans=a[mid];
            r=mid-1;
        }
        else l=mid+1;
    } 
    cout<<ans<<"\n";
  }
}
