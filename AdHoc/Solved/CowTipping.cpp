#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<string> board;

void flipBoard(int x, int y) 
{
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            board[i][j] = (board[i][j] == '1')?'0':'1';
        }
    }
}

int main()
{
    // For getting input from input.txt file
    freopen("cowtip.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;

    board.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(board[i][j] == '1') {
                flipBoard(i, j);
                ans++;
            }
        }
    }

    cout << ans << "\n";
}