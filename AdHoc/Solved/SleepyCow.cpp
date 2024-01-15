#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("herding.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("herding.out", "w", stdout);
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    //minimum steps
    if(((c1 + 2) == (c2 + 1)) && ((c2 + 1) == c3)) {
        cout << "0" << "\n" << "0" << "\n";
    } else {
        if(((c1 + 2) == c2) || ((c2 + 2) == c3)) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
        cout << max(c2 - c1, c3 - c2) - 1 << "\n";
    }
}