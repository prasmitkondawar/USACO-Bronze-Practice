#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    string s = "";
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> s;

        string s1 = s;
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        bool pali = (s2 == s1);

        if(s.length() < 10 || pali) cout << "B" << "\n";
        else if (s[s.length() - 1] == '0') cout << "E" << "\n";
        else cout << "B" << "\n";
    }
    
}