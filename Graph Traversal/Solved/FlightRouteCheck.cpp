#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(100005, false);
vector<bool> visR(100005, false);
vector<vector<long long>> flights(100005);
vector<vector<long long>> flightsR(100005);

void dfs(int index) {
        vis[index] = true;
        for(auto a: flights[index]) {
            if(!vis[a]) dfs(a);
        }
}

void dfsR(int index) {
        visR[index] = true;
        for(auto a: flightsR[index]) {
            if(!visR[a]) dfsR(a);
        }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        flights[a].push_back(b);
        flightsR[b].push_back(a);
    }

    dfs(1);
    dfsR(1);

    bool pathTrue = true;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            pathTrue = false;
            cout << "NO" << "\n";
            cout << "1 " << i << "\n";
            break;
        }

        if(!visR[i]) {
            pathTrue = false;
            cout << "NO" << "\n";
            cout << i << " 1" << "\n";
            break;
        }
    }

    if(pathTrue) cout << "YES" << "\n";
    
}