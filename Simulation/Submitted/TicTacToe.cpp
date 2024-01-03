//passed 8/10 cases (faild)
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
    vector<bool> hasUsed(26, false);
    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        board[i].resize(3);
        for(int j = 0; j < 3; j++) {
            board[i][j] = s[j];
            if(!hasUsed[int(s[j]) - 65]) {
                hasUsed[int(s[j]) - 65] = true;
                letters.push_back(s[j]);
            }
        }
    }

    //finding single digit answer
    int ans = 0;
    for(int i = 0; i < letters.size(); i++) {
        char c = letters[i];
        vector<vector<bool>> present(3);
        for(int j = 0; j < 3; j++) {
            present[j].resize(3);
            for(int k = 0; k < 3; k++) {
                present[j][k] = false;
                if(c == board[j][k]) {
                    present[j][k] = true;
                }
            }
        }

        if(present[0][0] && present[0][1] && present[0][2]) ans++;
        else if(present[1][0] && present[1][1] && present[1][2]) ans++;
        else if(present[2][0] && present[2][1] && present[2][2]) ans++;
        else if(present[0][1] && present[1][1] && present[2][1]) ans++;
        else if(present[0][2] && present[1][2] && present[2][2]) ans++;
        else if(present[0][0] && present[1][0] && present[2][0]) ans++;
        else if(present[0][0] && present[1][1] && present[2][2]) ans++;
        else if(present[0][2] && present[1][1] && present[2][0]) ans++;
    }

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
    for(int counter = 0; counter < letters.size() - 1; counter++) {
        char c = letters[counter];
        for(int i = counter + 1; i < letters.size(); i++) {
            char c2 = letters[i];
            bool x = false;
            bool y = false;
            bool found = false;
            for(int rows = 0; rows < 3; rows++) {
                for(int col = 0; col < 3; col++) {
                    if(board[rows][col] == c) {
                        x = true;
                    } else if(board[rows][col] == c2) {
                        y = true;
                    } else {
                        x = false;
                        y = false;
                        break;
                    }
                }

                if(x && y) {
                    found = true;
                    break;
                }
            }

            for(int rows = 0; rows < 3; rows++) {
                for(int col = 0; col < 3; col++) {
                    if(board[col][rows] == c) {
                        x = true;
                    } else if(board[col][rows] == c2) {
                        y = true;
                    } else {
                        x = false;
                        y = false;
                        break;
                    }
                }

                if(x && y) {
                    found = true;
                    break;
                }
            }

            for(int dia = 0; dia < 3; dia++) {
                if(board[dia][dia] == c) {
                    x = true;
                } else if (board[dia][dia] == c2) {
                    y = true;
                } else {
                    x = false;
                    y = false;
                    break;
                }

            }

            if(x && y) {
                    found = true;
            }

            for(int dia = 0; dia < 3; dia++) {
                if(board[2 - dia][dia] == c) {
                    x = true;
                } else if (board[2 - dia][dia] == c2) {
                    y = true;
                } else {
                    x = false;
                    y = false;
                    break;
                }
            
            }

            if(x && y) {
                found = true;
            }

            if(found) ans++;
        }
    }

    cout << ans << "\n";
}