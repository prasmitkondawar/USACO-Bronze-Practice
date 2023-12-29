#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
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
// mid = (l+r)/2      l=mid+1   r=mid
// mid = (l+r+1)/2    l=mid     r=mid-1
//std::cout << std::fixed; std::cout << std::setprecision(12); std::cout << z ;
using namespace std;
int n;
void subset(int i, vector <int> v)
{
    if(i>n)
    {
        cout<<"subset size "<<v.size()<<"\n";
        for(auto z:v) cout<<z<<' ';
        cout<<"\n";
        return;
    }
    // ith element should either be in the subset or not
    // not in subset 
    subset(i+1,v);
    v.push_back(i);
    subset(i+1,v);
}
void permutations(int i,vector <int> v,vector <bool> used)
{
     if(i>=n)
     {
         cout << "Permutation ";
         for(auto x:v) cout<<x<<' ';
         cout<<"\n";
         return;
     }
     else
     {
         for(int j=0;j<n;j++)
         {
             if(!used[j])
             {
                 v.push_back(j);
                 used[j]=true;
                 permutations(i+1,v,used);
                 used[j]=false;
                 v.pop_back();
             }
         }
     }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
// for every i from 1 to n we have 2 options -> O(2^n)
//   vector <int> temp;
//   subset(1,temp);

   //  1 << i   is equal to  2^i
   //  2^n subsets
   //  each subset will have correponding  binary string of length n
   //  each binary string will map to a unique number in the range [0,2^n-1]
//    vector <int> a(n);
//    int k;cin>>k;
//    f(i,n) cin>>a[i];
//    for(int i=0;i<(1<<n);i++)
//    {
//        // i -> look at binary rep. of i 
//        // there are n bits in the binary 
//        // if jth bit is set -> include the jth element
//        int c=0;
//        for(int j=0;j<n;j++)
//        {
//            if(i & (1<<j)) c++;
//        }
//        if(c==k)
//        {
//             cout<<"one of the subset of size k: "; 
//             for(int j=0;j<n;j++)
//             {
//                 if(i & (1<<j)) cout<<a[j]<<' ';
//             }
//             cout<<"\n";
//        }
//    }
    vector <int> temp;
    vector <bool> used(n,false);
    permutations(0,temp,used);
}