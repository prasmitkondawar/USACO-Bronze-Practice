#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<bool> distinct(n + 1, false);
        vector<int> val(n - 1);
        int totDistinct = 0;
        for(int l = 0; l < n - 1; l++) {
            int value;
            cin >> value;
            val[l] = value;
            if(!distinct[value]) {
                totDistinct++;
                distinct[value] = true;
            }
        }
        

        if(totDistinct < (n - 2)) cout << "-1" << "\n";
        else if(totDistinct == (n - 1)) {
            // bool canConstruct = true;
            // for(int j = 0; j < n - 2; j++) {
            //     if(val[j] <= val[j+1]) canConstruct = false;
            // }
            
            // if(!canConstruct) cout << -1 << "\n";
            if(n == 2 && val[0] == 2) {
                cout << -1 << "\n";
            } else {
                // for(int k = 0; k < n; k++) {
                //     cout << k + 1;
                //     if(k != n - 1) cout << " ";
                // }

                // cout << "\n";    
                int missing = -1;
                for(int i = 1; i < n + 1; i++)
                {
                    if(!distinct[i])
                    {
                        missing = i;
                        break;
                    }
                }

                for(int i = n - 2; i >= 0; i--)
                {
                    cout<<val[i]<<" ";
                }

                cout<<missing<<endl;
            }
        } else {
            // bool canConstruct = true;
            // for(int j = 0; j < n - 2; j++) 
            // {
            //     if(val[j] < val[j+1]) canConstruct = false;
            // }
            // if(!canConstruct)
            // {
            //     cout<<-1<<endl;
            //     continue;
            // }
            vector<int> p(n);
            int x = 0;
            int y = 0;
            for(int j = 1; j < n + 1; j++) {
                if(x == 0) {
                    if(!distinct[j]) x = j;
                } else if(y == 0) {
                    if(!distinct[j]) y = j;
                }
            }

            p[0] = min(x, y);
            p[n - 1] = max(x, y);
            p[n - 2] = val[0];

            int l = 0;
            int r = (n - 2);

            int counter = 1;
            while(l < r) {
                if(p[r] > p[l]) {
                    r--;
                    p[r] = val[counter];
                } else {
                    l++;
                    p[l] = val[counter];
                }

                counter++;
            }

            for(int k = 0; k < n; k++) {
                cout << p[k];
                if(k != n - 1) cout << " ";
            }
            cout << "\n";
        }
    }
}