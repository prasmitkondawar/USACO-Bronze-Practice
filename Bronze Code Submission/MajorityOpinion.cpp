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
    for(int test = 0; test < n; test++) {
        int c;
        cin >> c;
        vector<int> pref(c);
        vector<int> counter(c);
        for(int i = 0; i < n; i++) {
            cin >> pref[i];
            counter[pref[i] - 1]++;
        }
        
        string ans = "";
        for(int i = 0; i < n; i++) {
            vector<int> temp(n);
            temp[i] = pref[i];
            int posR = -1;
            int posL = -1;
            for(int left = 0; left < n; left++) {
                if(pref[left] == i + 1) posL = left; 
            }

            for(int right = n - 1; right >= 0; right--) {
                if(pref[right] == i + 1) posR = right;
            }

            while (posR != posL && (n > posR && posR > posL) && (0 < posL && posL < posR)) {
                if((double) counter[i] < (0.5 * (posR - posL))) {
                    int prevPosR = posR;
                    for(int j = posR; j > posL; j++) {
                        if(temp[j] == i + 1) {
                            posR = j;
                            break;
                        }
                    }
                    if(posR == prevPosR) {
                        for(int j = posL; j < posR; j++) {
                            if(temp[j] == i + 1) {
                                posL = j;
                                break;
                            }
                        }
                    }
                } else {
                    for(int j = posL; j < posR; j++) {
                        temp[j] = i + 1;
                    }
                }
            }

            for(int j = 0; j < temp; j++) {
                
            }
        }
    }
}