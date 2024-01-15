#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int numOdd = 0;
    int numEven = 0;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) numEven++;
        else numOdd++;
    }

    int ans = 0;
    // for(int i = 0;;i++) {
    //     if(i % 2 == 0) {
    //         if(numEven > 0) {
    //             ans++;
    //             numEven--;
    //         } else if(numOdd > 1) {
    //             ans++;
    //             numOdd -= 2;
    //         } else {
    //             if(numOdd == 1) ans--;
    //             break;
    //         }
    //     } else {
    //         if(numOdd > 0) {
    //             ans++;
    //             numOdd--;
    //         } else {
    //             break;
    //         }
    //     }
    // }

    if(numEven > numOdd) ans = 2 * numOdd + 1;
    else if(numEven == numOdd) ans = 2 * numOdd;
    else {
        numOdd -= numEven;
        ans += 2 * numEven;
        ans += 2 * (numOdd / 3);
        int remainder = numOdd % 3;
        if(remainder == 1) ans--;
        else if(remainder == 2) ans++;
    }
    cout << ans << "\n";
}