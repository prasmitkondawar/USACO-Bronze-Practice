#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int l, int r, int x)
{
    while (l < r) {
        int m = (l + r) / 2;
        //cout << "m: " << m << " l: " << l << " r: " << r << "\n";
 
        if(m > (nums.size() - 1)) {
            return -1;
            break;
        }

        if (nums[m] > x && x >= nums[m + 1]) {
            return (m + 1);
            break;
        }
        else if (nums[m] < x) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
 
    // If we reach here, then element was not present
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> dif (n);
    vector<int> difference(n);

    for(int i = 0; i < n; i++) {
        cin >> dif[i];
    }

    int counter = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        dif[i] -= t;
        if(dif[i] >= 0) {
            difference[i] = dif[i];
            counter++;
        }
    }

    sort(difference.rbegin(), difference.rend()); 

    for(int i = 0; i < q; i++) {
        int v, s;
        cin >> v >> s;
        int index = 0;
        if(s < dif[0]) {
            index = binarySearch(dif, 0, n - 1, s);
        }
        //while(difference[index] > s) index++;

        if(index >= v) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}