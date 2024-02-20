#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        vector<int> nums(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        if(sum == 0) {
            cout << "0" << "\n";
            continue;
        }
        vector<int> factors;
        for(int i = 1; i <= sqrt(sum); i++) {
            if(sum % i == 0) {
                factors.push_back(i);
                factors.push_back(sum/i);
            }
        }

        int totalSteps = n - 1;
        for(int f: factors) {
            int countSum = 0;
            int steps = 0;
            for(int i = 0; i < n; i++) {
                int j = i;
                int countSum = 0;
                while(j < n && countSum < f) {
                    countSum += nums[j];
                    j++;
                }
                j--;

                if(countSum == f) {
                    //cout << "i: " << i << " j: " << j << " f: " << f << "\n";
                    steps += j - i;
                    i = j;
                    countSum = 0;
                } else {
                    steps = n;
                    break;
                }
            }

            totalSteps = min(totalSteps, steps);
        }

        cout << totalSteps << "\n";
    }
}