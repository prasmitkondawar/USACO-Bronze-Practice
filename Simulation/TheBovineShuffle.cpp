#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> org(n);
    for(int i = 0; i < n; i++) {
        cin >> org[i];
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
            temp[rev[j]] = org[j];
        }

        for(int j = 0; j < n; j++) {
            org[j] = temp[j];
            temp[j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << org[i] << "\n";
    }
}