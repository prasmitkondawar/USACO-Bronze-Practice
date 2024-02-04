#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> board(n);

    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int ans = 0;
    int dir = 1;
    for(int i = 0; i < n - 1; i++) {
        ans += abs(board[i]);
        if(board[i] > 0) dir = -1;
        else dir = 1;
        for(int j = n - 1; j > i; j--) {
            board[j] += (j - i + 1) * (dir) * (abs(board[i]));
            //cout << board[j] << " ";
        }
        // cout << "\n";
        // cout << ans << "\n";
    }

    ans += abs(board[n - 1]);
    cout << ans << "\n";
}