#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, t;
    cin >> n >> k >> t;
    
    vector<int> active(k);
    for(int i = 0; i < k; i++) {
        cin >> active[i];
    }
    
    vector<int> cows(n);
    for(int i = 0; i < n; i++) {
        cows[i] = i;
    }

    for(int i = 0; i < t; i++) {
        //first rotation
        int temp = cows[active[0]];
        for(int j = 1; j < k; j++) {
            
        }
    }
}