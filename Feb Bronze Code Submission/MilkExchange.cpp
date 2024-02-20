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
    for(long long i = 0; i < n; i++) {
        dir[i] = s[i];
        // cout << s.at(i) << "\n";
    }

    long long totSum = 0;
    for(long long  i = 0; i < n; i++) {
        cin >> milks[i];
        totSum += milks[i];
    }

    for(long long i = 0; i < n; i++) {
        long long before = i - 1;
        long long after = i + 1;

        if(i == 0) before = n - 1;
        else if(i == (n - 1)) after = 0;

        char cBefore = dir[before];
        char cAfter = dir[after];
        char cCurrent = dir[i];
        
        // cout << cBefore << " " << cCurrent << " " << cAfter << "\n";

        if(cBefore == 'R' && cCurrent == 'R' && cAfter == 'L') {
            // cout << "inside" << "\n";
            long long search = before;
            long long bank = 0;
            while(dir[search] == 'R') {
                bank += milks[search];
                search--;
                if(search == -1) search = n - 1;
            }

            // cout << i << "\n";
            totSum -= min(bank, m);
        } else if(cBefore == 'R' && cCurrent == 'L' && cAfter == 'L') {
            // cout << i << "\n";
            long long search = after;
            long long bank = 0;
            while(dir[search] == 'L') {
                bank += milks[search];
                search++;
                if(search == n) search = 0;
            }

            totSum -= min(bank, m);
        }
    }

    cout << totSum << "\n";
}