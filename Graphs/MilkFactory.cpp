#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("factory.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("factory.out", "w", stdout);
    int n;
    cin >> n;

    vector<vector<int>> list(n + 1);
    for(int i = 1; i < n; i++) {
        int start, end;
        cin >> start >> end;
        list[start].push_back(end);
    }

    int ans = -1;
    bool foundAns = false;
    for(int i = 1; i < n + 1; i++) {
        if(list[i].size() > 1) {
            ans = -1;
            break;
        } else if(list[i].size() == 0) {
            if(!foundAns) {
                foundAns = true;
                ans = i;
            } else {
                ans = -1;
                break;
            }
        }
    }

    cout << ans << "\n";
}