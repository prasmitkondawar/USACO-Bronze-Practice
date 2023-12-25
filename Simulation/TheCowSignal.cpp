#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    
// For getting input from input.txt file
   freopen("cowsignal.in", "r", stdin);
  // Printing the Output to output.txt file
   freopen("cowsignal.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    
    //input
    vector<vector<char>> v;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        v[i].resize(m);
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            v[i][j] = s[j];
        }
    }

    //outputing answer
    for(int i = 0; i < n; i++) {
        for(int newline = 0; newline < k; newline++) {
            for(int j = 0; j < m; j++) {
                for(int newchar = 0; newchar < k; newchar++) {
                    cout << v[i][j];
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

}