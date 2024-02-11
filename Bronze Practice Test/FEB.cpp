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
    vector<vector<int>> freq(3);
    string s;
    cin >> s;

    vector<int> answer = {0, 0};
    bool isStreakF = false;
    bool isStreakBE = false;
    char startC = s[0];
    char endC = s[n - 1];
    int streak = 0;
    int constant = 0;
    for(int i = 1; i < n + 1; i++) {
        char c = s[i];
        if(isStreakBE || c == s[i-1]) {
            if(c == s[i-1]) {
                streak++;
                isStreakBE = true;
            } else {
                constant += streak;
                streak = 0;
                isStreakBE = false;
            }
        } else if(isStreakF || c == 'F') {
            if(c == 'F') {
                isStreakF = true;
                streak++;
            } else {
                endC = c;
                if(startC == endC) {
                    if(streak % 2 == 0) {
                        //add possible values (all odds of streak)
                    } else {
                        //add possible values (all evens of streak)
                    }
                } else if(startC != endC) {
                    if(streak % 2 == 0) {
                        //add possible values (all evens of streak)
                    } else {
                        //add possible values (all odds of streak)
                    }
                }
                isStreakF = false;
                streak = 0;
            }

            if(streak == 1) {
                startC = s[i-1];
            }
        }
    }

    cout << answer.size() << "\n";
    for(int i : answer) cout << i << "\n";
}