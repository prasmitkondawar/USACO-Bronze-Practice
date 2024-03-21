#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(30001, false);
vector<bool> open(30001, true);
vector<vector<int>> farms(30005);
int openFarms = 0;

void dfs(int index) {
    //cout << vis[index] << " " << open[index] << "\n";
    if(!vis[index] && open[index]) {
        vis[index] = true;
        for(auto a: farms[index]) {
            if(!vis[a] && open[a]) {
                openFarms++;
                dfs(a);
                //cout << a << "\n";
            }
        }
    }
}

int main()
{
    // For getting input from input.txt file
    freopen("closing.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("closing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> closing(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        farms[a].push_back(b);
        farms[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        cin >> closing[i];
    }

    for(int i = 0; i < n - 1; i++) {
        openFarms = 1;
        dfs(closing[i]);
        //cout << openFarms << " compares to " << n - i << "\n";
        if(openFarms == (n - i)) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        open[closing[i]] = false;
        for(int i = 1; i <= n; i++) vis[i] = false;
    }

    cout << "YES" << "\n";

}