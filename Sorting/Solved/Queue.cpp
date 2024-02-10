#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("cowqueue.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);

    for(int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int time = cows[0].first + cows[0].second;
    for(int i = 1; i < n; i++) {
        if(time < cows[i].first) {
            int dif = cows[i].first - time;
            time += dif + cows[i].second;
        } else {
            time += cows[i].second;
        }
    }

    cout << time << "\n";
}