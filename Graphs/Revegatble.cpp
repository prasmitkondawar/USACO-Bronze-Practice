#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("revegetate.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> list(n + 1);
    for(int i = 0; i < m; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        list[f1].push_back(f2);
        list[f2].push_back(f1);
    }

    string s = "1";
    for(int i = 2; i < n + 1; i++) {
        vector<bool> canUse(5, true);
        for(int j: list[i]) {
            if(j < i) {
                canUse[s[j - 1] - '0'] = false;
            }
        }

        for(int j = 1; j < 5; j++) {
            if(canUse[j]) {
                s += j + 48;
                break;
            }
        }
    }

    cout << s << "\n";
}