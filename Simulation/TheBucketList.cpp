#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    // For getting input from input.txt file
    freopen("blist.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("blist.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> cows(n);

    //input format: (si, ti, bi)
    for(int i = 0; i < n; i++) {
        cows[i].resize(3);
        int si, ti, bi;
        cin >> si >> ti >> bi;
        cows[i][0] = si;
        cows[i][1] = ti;
        cows[i][2] = bi;
    }

    vector<int> time(1001);
    for(int i = 0; i < n; i++) {
        for(int j = cows[i][0]; j <= cows[i][1]; j++) {
            time[j] += cows[i][2];
        }
    }

    int max = 0;
    for(int i = 0; i < 1001; i++) {
        if(time[i] > max) {
            max = time[i];
        }
    }

    cout << max << "\n";
}