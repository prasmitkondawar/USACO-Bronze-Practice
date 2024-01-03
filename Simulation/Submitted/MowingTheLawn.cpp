#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
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

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> directions;
    f(i, n) cin >> directions[i].F >> directions[i].S;

    //finding starting point
    int xi, yi, x, y;
    int xi = 0;
    int yi = 0;
    f(i, n) {
        if(directions[i].F == "N") {
            y += directions[i].S;
        } else if (directions[i].F == "S") {
            y -= directions[i].S;
        } else if (directions[i].F == "E") {
            x += directions[i].S;
        } else {
            x -= directions[i].S;
        }

        if(x < xi) xi = x;
        if(y < yi) yi = y;
    }

    xi = -xi;
    yi = -yi;

    //resizing field
    vector<vector<int>> field(1000);
    f(i, 1001) {
        field[i].resize(1001);
        f(j, 1000) {
            field[i][j] = -1;
        }
    }

    //simulation
    int ans = INT_MAX;
    int time = 0;
    f(i, n) {
        int steps = directions[i].S;
        string dir = directions[i].F;

        f(j, steps) {
            if(dir == "N") {
                yi++;
            } else if(dir == "S") {
                yi--;
            } else if(dir == "E") {
                xi++;
            } else {
                xi--;
            }

            if(field[xi][yi] != -1) {
                int dif = time - field[xi][yi];
                ans = min(ans, dif);
            }

            field[xi][yi] = time;
            time++;
        }
    }

    if(ans == INT_MAX) {
        cout << "-1" << "\n";
    } else {
        cout << ans << "\n";
    }
}