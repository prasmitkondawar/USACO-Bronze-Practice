#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("censor.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("censor.out", "w", stdout);
    string s = "";
    string t = "";
    cin >> s >> t;
    string ans = s.substr(0, t.length() - 1);
    for(int i = t.length() - 1; i < s.length(); i++) {
        ans += s[i];
        string subS = "";
        if(ans.length() >= t.length()) subS = ans.substr(ans.length() - t.length(), t.length());

        if(subS == t) ans.resize(ans.length() - t.length());
    }

    cout << ans << "\n";
}