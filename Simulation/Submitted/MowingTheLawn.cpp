#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#define ll         long long int
#define pr1         pair<ll,ll>
#define F          first
#define S          second
#define mP         make_pair
#define f(i,n)     for(ll i=0;i<n;i++) 

using namespace std;

int main()
{
        // For getting input from input.txt file
    freopen("mowing.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("mowing.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<string, int>> directions(n);
    f(i, n) {
        string dir;
        int step;
        cin >> dir >> step;
        directions[i] = mP(dir, step);
    }
    //finding starting point
    int xi, yi, x, y;
    xi = 0;
    yi = 0;
    x = 0;
    y = 0;
    f(i, n) {
        if(directions[i].F == "N") {
            y += directions[i].S;
        } else if (directions[i].F == "S") {
            y -= directions[i].S;
        } else if (directions[i].F == "E") {
            x += directions[i].S;
        } else {
            x -= directions[i].S;
        }

        if(x < xi) xi = x;
        if(y < yi) yi = y;
    }

    xi = -1 * xi;
    yi = -1 * yi;

    //resizing field
    vector<vector<int>> field(2001, vector<int> (2001, -1));
    // f(i, 2000) {
    //     field[i].resize(2001);
    //     f(j, 2000) {
    //         field[i][j] = -1;
    //     }
    // }

    //simulation
    int ans = INT_MAX;
    int time = 0;
    f(i, n) {
        int steps = directions[i].S;
        string dir = directions[i].F;

        f(j, steps) {
            if(dir == "N") {
                yi++;
            } else if(dir == "S") {
                yi--;
            } else if(dir == "E") {
                xi++;
            } else {
                xi--;
            }

            if(field[xi][yi] != -1) {
                int dif = time - field[xi][yi];
                ans = min(ans, dif);
            }
            field[xi][yi] = time;
            time++;
        }
    }

    if(ans == INT_MAX) {
        cout << "-1" << "\n";
    } else {
        cout << ans << "\n";
    }
}