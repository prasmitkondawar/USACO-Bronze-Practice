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
    vector<int> kayaks(2 * n);

    for(int i = 0; i < (2 * n); i++) {
        cin >> kayaks[i];
    }

    sort(kayaks.begin(), kayaks.end());

    int ans = 100000;
    for(int i = 0; i < (2 * n - 1); i++) {
        for(int j = i + 1; j < (2 * n); j++) {
            int temp = 0;
            int sign = -1;
            for(int k = 0; k < (2 * n); k++) {
                if(k != i && k != j) {
                    temp += kayaks[k] * sign;
                    sign *= -1;
                }
            }

            ans = min(ans, temp);
        }
    }

    cout << ans << "\n";
}