#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    // For getting input from input.txt file
    freopen("shuffle.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> org(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        org[i] = num - 1;
    }

    vector<int> id(n);
    for(int i = 0; i < n; i++) {
        cin >> id[i];
    }

    vector<int> rev(n);
    for(int i = 0; i < n; i++) {
        rev[org[i]] = i;
    }

    vector<int> temp(n);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            temp[rev[j]] = id[j];
        }

        for(int j = 0; j < n; j++) {
            id[j] = temp[j];
        }
    }

    for(int i = 0; i < n; i++) {
        cout << id[i] << "\n";
    }
}