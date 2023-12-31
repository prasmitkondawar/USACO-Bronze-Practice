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

    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<int> answer(26);
    for(int i = 0; i < 26; i++) {
        char letter = alphabet[i];
        for(int j = 0; j < n; j++) {
            string s1 = get<1>(blocks[i]);
            string s2 = get<2>(blocks[i]);
            int counter1 = 0;
            int counter2 = 0;
            for(int c1 = 0; c1 < s1.length(); c1++) {
                if(s1[c1] == letter) {
                    counter1++;
                }
            }

            for(int c2 = 0; c2 < s2.length(); c2++) {
                if(s2[c2] == letter){
                    counter2++;
                }            
            }

            answer[i] += max(counter1, counter2);
        }
    }

    f(i, 26) {
        cout << answer[i] << "\n";
    }

    // I Think the approach used generating all possible 2^n combinations of blocks 
    // and then for each character it's checking maximum frequency of it among all 2^n combinations
    // Time coplexity is  2^n * (10+10)   , since length of each word can be at max 10
    // This will give TLE since 2^100 is super large number
    // Think it the way like in which combination maximum number of a's would be used , in which max. b will be used ...
    // if input is 
    // n = 3 
    // abba baaa
    // acds dbdb
    // gaad alls
    // we can say that max a will be used for this combination of words baaa acds gaad
    // Maximum number of a's will be req. if for each block we chose the word having greater freq. of a 
    // Similarly we can go for other character
}
