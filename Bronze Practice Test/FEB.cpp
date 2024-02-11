#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int base=0;
    vector <pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='F')
        {
           int len=0;
           int j=i;
           while(j<n && s[j]==s[i]) j++;
                   -   --;

           len=j-i;
           i=j;
        }
        else 
        {
          if(i>0 && s[i]==s[i-1]) base++;
        }
    }

    // vector<int> answer = {0, 0};
    // bool isStreakF = false;
    // int length = 0;
    // int constant = 0;
    // char left = s[0];
    // char right = s[n - 1];
    // for(int i = 1; i < n - 1; i++) {
    //     if(s[i] == 'F') {
    //         isStreakF = true;
    //     } else {
    //         isStreakF = false;
    //     }

    //     if(isStreakF) {
    //         length++;
    //     }
    // }
}