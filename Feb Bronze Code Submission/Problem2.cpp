#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<char> dir(n);
    vector<long long> milks(n);
	string s  = "";
	cin >> s;
    for(int i = 0; i < n; i++) {
        dir[i] = s[i];
        // cout << s.at(i) << "\n";
    }

    long long totSum = 0;
    for(long long  i = 0; i < n; i++) {
        cin >> milks[i];
        totSum += milks[i];
    }

    for(int i = 0; i < n; i++) {
        long long before = i - 1;
        long long after = i + 1;

        if(i == 0) before = n - 1;
        else if(i == (n - 1)) after = 0;

        char cBefore = dir[before];
        char cAfter = dir[after];
        char cCurrent = dir[i];
        
        // cout << cBefore << " " << cCurrent << " " << cAfter << "\n";

        if(cBefore == cCurrent && cCurrent == 'R' && cAfter == 'L') {
            // cout << "inside" << "\n";
            long long search = before;
            long long lMilk = 0;
            while(dir[search] == 'R') {
                lMilk += milks[search];
                search--;
                if(search == -1) search = n - 1;
            }

            // cout << i << "\n";
            totSum -= min(lMilk, m);
        } else if(cBefore == 'R' && cCurrent == 'L' && cAfter == cCurrent) {
            // cout << i << "\n";
            long long search = after;
            long long lMilk = 0;
            while(dir[search] == 'L') {
                lMilk += milks[search];
                search++;
                if(search == n) search = 0;
            }

            totSum -= min(lMilk, m);
        }
    }

    cout << totSum << "\n";
}