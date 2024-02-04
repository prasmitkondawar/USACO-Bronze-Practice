#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<long> ai(n);
    vector<long> bi(n);

    for(int i = 0; i < n; i++) {
        cin >> ai[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> bi[i];
    }

    for(int i = 0; i < n; i++) {
        ai[i] = ai[i] * (i + 1) * (n - i);
    }

    sort(ai.begin(), ai.end());
    sort(bi.rbegin(), bi.rend());

    long score = 0;
    for(int i = 0; i < n; i++) {
        score += ai[i] * bi[i];
    }

    cout << score << "\n";
}