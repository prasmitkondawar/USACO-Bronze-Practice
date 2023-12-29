#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

//1/10 first one was correct
int main() 
{
    // For getting input from input.txt file
    freopen("traffic.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("traffic.out", "w", stdout);
    int n;
    cin >> n;
    vector<tuple<string, int, int>> info(n);

    for(int i = 0; i < n; i++) {
        string type;
        int lower, upper;
        cin >> type >> lower >> upper;
        info[i] = make_tuple(type, lower, upper); 
    }

    //simulating for the start
    int startLower, startUpper, startI;
    for(int i = n - 1; i >= 0; i--) {
        if(get<0>(info[i]) == "none") {
            startLower = get<1>(info[i]);
            startUpper = get<2>(info[i]);
            startI = i;
            break;
        }
    }

    //simulating from the back to the front
    for(int i = startI; i >= 0; i--) {
        string type = get<0>(info[i]);
        if(type == "none") {
            int cLower, cUpper;
            cLower = get<1>(info[i]);
            cUpper = get<2>(info[i]);

            if(cLower > startLower) {
                startLower = cLower;
            }

            if(cUpper < startUpper) {
                startUpper = cUpper;
            }
        } else if (type == "on") {
            int lower, upper;
            lower = get<1>(info[i]);
            upper = get<2>(info[i]);

            startLower -= upper;
            startUpper -= lower;

            if(startUpper < 0) {
                startUpper = 0;
            }

            if(startLower < 0) {
                startLower = 0;
            }
        } else {
            int lower, upper;
            lower = get<1>(info[i]);
            upper = get<2>(info[i]);

            startLower += lower;
            startUpper += upper;
        }
    }

    cout << startLower << " " << startUpper << "\n";

    //simulating forward to ending range
    int endLower, endUpper, endI;
    for(int i = 0; i < n; i++) {
        if(get<0>(info[i]) == "none") {
            endLower = get<1>(info[i]);
            endUpper = get<2>(info[i]);
            endI = i;
            break;
        }
    }

    //simulating from the back to the front
    for(int i = endI; i < n; i++) {
        string type = get<0>(info[i]);
        if(type == "none") {
            int cLower, cUpper;
            cLower = get<1>(info[i]);
            cUpper = get<2>(info[i]);

            if(cLower > endLower) {
                endLower = cLower;
            }

            if(cUpper < endUpper) {
                endUpper = cUpper;
            }
        } else if (type == "on") {
            int lower, upper;
            lower = get<1>(info[i]);
            upper = get<2>(info[i]);

            endLower += lower;
            endUpper += upper;

            
        } else {
            int lower, upper;
            lower = get<1>(info[i]);
            upper = get<2>(info[i]);

            endLower -= upper;
            endUpper -= lower;

            if(endLower < 0) {
                endLower = 0;
            }

            if(endUpper < 0) {
                endUpper = 0;
            }
        }
    }

     cout << endLower << " " << endUpper << "\n";
}