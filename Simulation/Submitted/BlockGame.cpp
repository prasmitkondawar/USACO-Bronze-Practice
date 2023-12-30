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
#define yes        cout<<"Yes"<<"\n"
#define no         cout<<"No"<<"\n"
#define modsum(a,b)  ((a%mod)+(b%mod))%mod
#define modpro(a,b)  ((a%mod)*(b%mod))%mod
#define moddif(a,b)  ((a%mod)-(b%mod)+mod)%mod
#define modsumt(a,b,c) modsum(a,modsum(b,c))

int main() 
{
    // For getting input from input.txt file
    freopen("blocks.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("blocks.out", "w", stdout);
    vector<tuple<int, string, string>> blocks;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string front, back;
        cin >> front >> back;
        blocks[i] = make_tuple(0, front, back);
    }

    // vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<int> answer(26);
    while(get<0>(blocks[n-1]) < 2) {
        vector<int> temp(26);
        string s;
        for(int i = 0; i < n; i++) {
            int sign = get<0>(blocks[i]);
            if(sign == 1) {
                s += get<2>(blocks[i]);
            } else {
                s += get<1>(blocks[i]);
            }
        }

        for(int i = 0; i < s.length(); i++) {
            temp[int(s[i]) - 97]++;
        }

        for(int i = 0; i < 26; i++) {
            answer[i] = max(temp[i], answer[i]);
        }

        for(int i = 0; i < n - 1; i++) {
            if(i == 0) {
                get<0>(blocks[i])++;
            }
            if(get<0>(blocks[i]) == 2) {
                get<0>(blocks[i]) = 0;
                get<0>(blocks[i+1])++;
            }
        }
    }

    f(i, 26) {
        cout << answer[i] << "\n";
    }
}