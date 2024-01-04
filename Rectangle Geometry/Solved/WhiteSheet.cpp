#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll         long long int
#define umap       unordered_map
#define mod        1000000007ll
#define pb         push_back
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()
#define MN          (a,b,c)  min(a,min(b,c))
#define MX(a,b,c)  max(a,max(b,c))
#define pr1         pair<ll,ll>
#define F          first
#define Ssecond
#define mP         make_pair
#define f(i,n)     for(ll i=0;i<n;i++) 
#define f1(i,x,y)  for(ll i=x;i<=y;i++)
#define f2(i,x,y)  for(ll i=x;i>=y;i--)
#define yes        cout<<"YES"<<"\n"
#define no         cout<<"NO"<<"\n"
#define modsum(a,b)  ((a%mod)+(b%mod))%mod
#define modpro(a,b)  ((a%mod)*(b%mod))%mod
#define moddif(a,b)  ((a%mod)-(b%mod)+mod)%mod
#define modsumt(a,b,c) modsum(a,modsum(b,c))

int main() 
{
    vector<int> whitePaper(4);
    vector<int> bP1(4);
    vector<int> bP2(4);

    //input
    f(i , 4) {
        cin >> whitePaper[i];
    }

    f(i , 4) {
        cin >> bP1[i];
    }

    f(i , 4) {
        cin >> bP2[i];
    }

    //area of the first black paper and white paper
    int xi = max(bP1[0], whitePaper[0]);
    int xf = min(bP1[2], whitePaper[2]);
    int yi = max(bP1[1], whitePaper[1]);
    int yf = min(bP1[3], whitePaper[3]);

    int a1 = 0;
    if(xi < xf && yi < yf) {
        a1 = (xf - xi) * (yf - yi);
    }

    //finding area of second black paper and white paper
    int xi2 = max(bP2[0], whitePaper[0]);
    int xf2 = min(bP2[2], whitePaper[2]);
    int yi2 = max(bP2[1], whitePaper[1]);
    int yf2 = min(bP2[3], whitePaper[3]);

    int a2 = 0;
    if(xi2 < xf2 && yi2 < yf2) {
        a2 = (xf2 - xi2) * (yf2 - yi2);
    }

    //finding area compared to white paper
    int aWhite = (whitePaper[2] - whitePaper[0]) * (whitePaper[3] - whitePaper[1]);
    if(a1 + a2 >= aWhite) no;
    else yes;
}