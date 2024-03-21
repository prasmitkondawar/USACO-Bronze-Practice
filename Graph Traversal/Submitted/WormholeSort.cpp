#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> c;
vector<long long> position;
int x = 0;
vector<bool> vis;
vector<vector<int>> adj(100005);

bool hasParts() {
    for(int i = 1; i < c.size(); i++) {
        if(c[i] != c[position[i]]) {
            return false;
        }
    }

    return true;
}

void dfs(int index) {
    vis[index] = true;
    c[index] = x;
    for(auto a: adj[index]) {
        if(!vis[a]) {
            dfs(a);

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // For getting input from input.txt file
    freopen("wormsort.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    position.resize(n + 1);
    vis.resize(n + 1);
    vector<vector<long long>> wormholes(m);

    bool firstTrue = true;
    for(int i = 1; i <= n; i++) {
        cin >> position[i];
        if(firstTrue && i > 1) {
            firstTrue = ((position[i]-1) == (position[i-1]));
        }
    }

    for(int i = 0; i < m; i++) {
        long long a, b, w;
        cin >> a >> b >> w;
        wormholes[i].push_back(w);
        wormholes[i].push_back(a);
        wormholes[i].push_back(b);
    }

    if(firstTrue) cout << "-1" << "\n";
    else {
        sort(wormholes.begin(), wormholes.end());
        int ans = wormholes[0][0];

        int l = 0;
        int r = m - 1;
        while(l <= r) {
            int mid = (l + r) / 2;

            for(int i = mid; i < m; i++) {
                adj[wormholes[i][1]].push_back(wormholes[i][2]);
                adj[wormholes[i][2]].push_back(wormholes[i][1]);
            }

            for(int i = 1; i <= n; i++) {
                if(!vis[i]) {
                    dfs(i);
                    x++;
                }
            }

            if(hasParts()) {
                ans = wormholes[mid][0];
                l = mid + 1;
            } else {
                r = mid - 1;
            }

            x = 0;
            for(int i = 1; i <= n; i++) {
                adj[i].clear();
                vis[i] = false;
            }
        }
        
        cout << ans << "\n";
    }

}