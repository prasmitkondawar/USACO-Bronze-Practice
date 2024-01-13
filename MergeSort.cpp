#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int inversion = 0;
vector<int> mergeSort(vector<int> v) 
{
    if(v.size() == 2) {
        if(v[0] < v[1]) {
            int temp = v[0];
            v[0] = v[1];
            v[1] = temp;
            inversion++;
            return v;
        } else {
            vector<int> v1 (v.size()/2);
            vector<int> v2 (v.size()/2);
            for(int i = 0; i < v.size()/2; i++) {
                v1[i] = v[i];
                v2[i] = v[v.size() - i - 1];
            }

            vector<int> v1Sorted = mergeSort(v1);
            vector<int> v2Sorted = mergeSort(v2);

            int counter1 = 0;
            int counter2 = 0;
            int counter = 0;
            while(counter1 < v.size()/2 && counter2 < v.size()/2) {
                if(v1[counter1] < v2[counter2]) {
                    v[counter] = v1[counter1];
                    counter1++;
                    counter++;
                } else {
                    v[counter] = v2[counter2];
                    counter2++;
                    counter++;
                    inversion += v.size()/2 - counter1;
                }
            }

            cout << "Number of inversion: " << inversion;
            return v;
        }
    }
}
int main() 
{
    int n;
    cin >> n;
    vector<int> v (n);
    mergeSort(v);
}