#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("planting.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("planting.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> edges(n + 1, 0);

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edges[x]++;
        edges[y]++;
    }

    int ans = 0;
    for(auto x: edges) {
        ans = max(x, ans);
    }

    cout << ans + 1 << "\n";
}