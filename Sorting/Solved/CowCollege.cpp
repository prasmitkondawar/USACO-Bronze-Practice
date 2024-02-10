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
    vector<long> tuition(n);
    
    for(int i = 0; i < n; i++) {
        cin >> tuition[i];
    }

    sort(tuition.begin(), tuition.end());

    long total = 0;
    long tuit = 0;
    for(int i = 0; i < n; i++) {
        long temp = (tuition[i] * (n - i));
        if(temp > total) {
            total = temp;
            tuit = tuition[i];
        }
    }

    cout << total << " " << tuit << "\n";
}