#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<vector<int>> board(n);
    int numBoards = 0;
    for(int i = 0; i < n; i++) {
        board[i].resize(3);
        int type, value;
        cin >> type >> value;
        board[i][0] = type;
        board[i][1] = value;
        if(type == 1) {
            numBoards++;
            board[i][2] = 1;
        } else {
            board[i][2] = 0;
        }
    }

    bool infinite = false;
    s--;
    int ans = 0;
    int dir = 1;
    int jump = 1;
    vector<int> prevPos;
    int steps = 0;
    // cout << s + 1 << "\n";
    // cout << numBoards << " <- Numboards" << "\n";
    while(0 <= s && s < n && !infinite && numBoards > ans) {
        if(board[s][0] == 1 && board[s][2] && jump >= board[s][1]) {
            ans++;
            board[s][2] = false;
        } else if (board[s][0] == 0) {
            jump += board[s][1];
            dir *= -1;
        }

        prevPos.push_back(s);
        // if(prevPos.size() >= 4) {
        //     if((prevPos[steps] == prevPos[steps - 2]) && (prevPos[steps - 1] == prevPos[steps - 3])) infinite = true;
        // }
        //steps++;

        s += (jump * dir);
        if(0 > s && s >= n) break;
        //cout << s + 1 << " Answer: " << ans << " Jump, dir: " << jump << " " << dir << "\n";
    }
    cout << ans << "\n";

}