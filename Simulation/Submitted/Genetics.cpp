#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("cownomics.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<string> spotty(n);
    vector<string> plain(n);

    for(int i = 0; i < n; i++) {
        cin >> spotty[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> plain[i];
    }

    int count = 0;
    for(int i = 0; i < m - 2; i++) {
        for(int j = i + 1; j < m - 1; j++) {
            for(int k = j + 1; k < m; k++) {
                string sP = "";
                string sS = "";
                map <string, int> mp;
                for(int a = 0; a < n; a++) {
                    sS += spotty[a][i];
                    sS += spotty[a][j];
                    sS += spotty[a][k];
                    mp[sS]++;
                    sS = "";
                }

                bool found = false;
                for(int a = 0; (a < n) && !found; a++) {
                    sP += plain[a][i];
                    sP += plain[a][j];
                    sP += plain[a][k];

                    if(mp[sP] > 0) {
                        found = true;
                    }
                    sP = "";
                }

                if(!found) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";
}