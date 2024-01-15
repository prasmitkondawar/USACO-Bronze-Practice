#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("breedflip.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("breedflip.out", "w", stdout);
	int n;
    string a, b;
    cin >> n >> a >> b;
    bool prevState = (a[0] != b[0]);
    int ans = 0;
    for(int i = 1; i < a.size(); i++) {
        bool currState = (a[i] != b[i]);
        if(prevState && !currState) ans++;
        else if((i == a.size() - 1) && currState) ans++;

        prevState = currState;
    }

    cout << ans << "\n";
}