#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    // For getting input from input.txt file
    freopen("cbarn.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> barn(n);
    int totCows = 0;

    for(int i = 0; i < n; i++) {
        cin >> barn[i];
        totCows += barn[i];
    }

    //simulating the movement of cows
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        int cows = totCows;
        int counter = i;
        int distance = 0;
        while(cows > 0) {
            cows -= barn[counter];
            distance += cows;
            counter++;
            counter %= n;
            
        }

        if(distance < ans) {
            ans = distance;
        }
    }

    cout << ans << "\n";
}