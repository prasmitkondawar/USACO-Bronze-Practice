#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("tttt.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("tttt.out", "w", stdout);

    vector<vector<char>> board(3);
    vector<char> letters;
    vector<bool> hasUsed(26, true);
    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 3; j++) {
            board[i][j] = s[j];
            board.resize(3);
            if(!hasUsed[int(s[j]) - 97]) {
                hasUsed[int(s[j]) - 97] = false;
                letters.push_back(s[j]);
            }
        }
    }

    //finding single digit answer
    int ans = 0;
    // for(int i = 0; i < letters.size(); i++) {
    //     char c = letters[i];
    //     vector<vector<bool>> present(3);
    //     for(int j = 0; j < 3; j++) {
    //         present.resize(3);
    //         for(int k = 0; k < 3; k++) {
    //             if(c == board[j][k]) {
    //                 present[j][k] = true;
    //             }
    //         }
    //     }

    //     if(present[0][0] && present[0][1] && present[0][2]) ans++;
    //     else if(present[1][0] && present[1][1] && present[1][2]) ans++;
    //     else if(present[2][0] && present[2][1] && present[2][2]) ans++;
    //     else if(present[2][1] && present[1][1] && present[2][1]) ans++;
    //     else if(present[0][2] && present[1][2] && present[2][2]) ans++;
    //     else if(present[0][0] && present[1][0] && present[2][0]) ans++;
    //     else if(present[0][0] && present[1][1] && present[2][2]) ans++;
    //     else if(present[0][2] && present[1][1] && present[2][0]) ans++;
    // }

    // vector<bool> present(letters.size(), false);
    // if(board[0][0] == board[0][1]  && board[0][1] == board[0][2] && ) ans++;
    // else if((board[1][0] == c || board[1][0] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[1][2] == c || board[1][2] == c2)) ans++;
    // else if((board[2][0] == c || board[2][0] == c2) && (board[2][1] == c || board[2][1] == c2) && (board[2][2] == c || board[2][2] == c2)) ans++;
    // else if((board[0][0] == c || board[0][0] == c2) && (board[1][0] == c || board[1][0] == c2) && (board[2][0] == c || board[2][0] == c2)) ans++;
    // else if((board[0][1] == c || board[0][1] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[2][1] == c || board[2][1] == c2)) ans++;
    // else if((board[0][2] == c || board[0][2] == c2) && (board[1][2] == c || board[1][2] == c2) && (board[2][2] == c || board[2][2] == c2)) ans++;
    // else if((board[0][0] == c || board[0][0] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[2][2] == c || board[2][2] == c2)) ans++;
    // else if((board[2][0] == c || board[2][0] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[0][2] == c || board[0][2] == c2)) ans++;

    cout << ans << "\n";

    //finding double team answer
    ans = 0;
    for(int counter = 0; counter < letters.size(); counter++) {
        char c = letters[counter];
        for(int i = counter; i < letters.size(); i++) {
            char c2 = letters[i];
            vector<vector<bool>> board(3);

            if((board[0][0] == c || board[0][0] == c2) && (board[0][1] == c || board[0][1] == c2) && (board[0][2] == c || board[0][2] == c2)) ans++;
            else if((board[1][0] == c || board[1][0] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[1][2] == c || board[1][2] == c2)) ans++;
            else if((board[2][0] == c || board[2][0] == c2) && (board[2][1] == c || board[2][1] == c2) && (board[2][2] == c || board[2][2] == c2)) ans++;
            else if((board[0][0] == c || board[0][0] == c2) && (board[1][0] == c || board[1][0] == c2) && (board[2][0] == c || board[2][0] == c2)) ans++;
            else if((board[0][1] == c || board[0][1] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[2][1] == c || board[2][1] == c2)) ans++;
            else if((board[0][2] == c || board[0][2] == c2) && (board[1][2] == c || board[1][2] == c2) && (board[2][2] == c || board[2][2] == c2)) ans++;
            else if((board[0][0] == c || board[0][0] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[2][2] == c || board[2][2] == c2)) ans++;
            else if((board[2][0] == c || board[2][0] == c2) && (board[1][1] == c || board[1][1] == c2) && (board[0][2] == c || board[0][2] == c2)) ans++;
        }
    }

    cout << ans << "\n";
}