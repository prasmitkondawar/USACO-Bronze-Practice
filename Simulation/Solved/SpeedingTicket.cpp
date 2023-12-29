#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    
// For getting input from input.txt file
   freopen("speeding.in", "r", stdin);
  // Printing the Output to output.txt file
   freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    //speed 
    //<length, speed>
    vector<pair<int, int>> speedLimit;
    speedLimit.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> speedLimit[i].first >> speedLimit[i].second;
    }

    vector<pair<int, int>> cowSpeed;
    cowSpeed.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> cowSpeed[i].first >> cowSpeed[i].second;
    }


    //setting the board up
    vector<int> sLBoard;
    sLBoard.resize(101);
    int i = 0;
    for(int counter = 0; counter < n; counter++) {
        for(int j = 0; j < speedLimit[counter].first; j++) {
            sLBoard[i] = speedLimit[counter].second;
            i++;
        }
    }

    vector<int> cSBoard;
    cSBoard.resize(101);
    i = 0;
    for(int counter = 0; counter < m; counter++) {
        for(int j = 0; j < cowSpeed[counter].first; j++) {
            cSBoard[i] = cowSpeed[counter].second;
            i++;
        }
    }


    //comparing speed
    int ans = 0;
    for(int i = 0; i < 100; i++) {
        if(cSBoard[i] - sLBoard[i] > ans) {
            ans = cSBoard[i] - sLBoard[i];
        }
    }

    cout << ans << "\n";
}