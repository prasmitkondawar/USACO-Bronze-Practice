#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("angry.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("angry.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> bales(n);
    for(int i = 0; i < n; i++) {
        cin >> bales[i];
    }

    sort(bales.begin(), bales.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int temp = 1;
        int factorL = 1;
        int factorR = 1;
        for(int startL = i - 1; startL >= 0; startL--) {
            int l = startL;
            while(l >= 0 && bales[l] >= (bales[startL + 1] - factorL)) {
                l--;
                temp++;
            }

            if(l == startL) break;
            factorL++;
            startL = l + 1;
        }

        for(int startR = i + 1; startR < n; startR++) {
            int r = startR;
            while(r < n && bales[r] <= (bales[startR - 1] + factorR)) {
                r++;
                temp++;
            }
            
            if(r == startR) break;
            factorR++;
            startR = r - 1;
        }

        ans = max(temp, ans);
    }

    cout << ans << "\n";
}