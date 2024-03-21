#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// problem reference: https://codeforces.com/problemset/problem/1941/D


int main()
{
    int t;
    cin >> t;
    for(int counter = 0; counter < t; counter++) {
        int n, m, s;
        cin >> n >> m >> s;
        vector<pair<int, char>> v(m);
        for(int i = 0; i < m; i++) {
            cin >> v[i].first >> v[i].second;
        }

        queue<int> orderOfBall;
        orderOfBall.push(s);
        int listBall = 1;
        for(int i = 0; i < m; i++) {
            while(listBall > 0) {
                if(v[i].second == '0') {
                    int index = orderOfBall.front() + (v[i].first % n);
                    if(orderOfBall.front() + (v[i].first % n) > 0) index = (orderOfBall.front() + v[i].first) % n;
                    else if(orderOfBall.front() + (v[i].first % n) == 0) index = n;
                    orderOfBall.pop();
                    cout << "Index: " << index << "\n";
                    listBall--;
                } else if(v[i].second == '1') {
                    int num = orderOfBall.front() - (v[i].first % n);
                    int index = num;
                    if(num < 0) {
                        index = n + num;
                    } else if(num == 0) {
                        index = n;
                    }
                    orderOfBall.push(index);
                    orderOfBall.pop();
                    cout << "Index: " << index << "\n";
                    listBall--;
                } else {
                    int index = orderOfBall.front() + (v[i].first % n);
                    if(orderOfBall.front() + (v[i].first % n) > 0) index = (orderOfBall.front() + v[i].first) % n;
                    else if(orderOfBall.front() + (v[i].first % n) == 0) index = n;
                    orderOfBall.push(index);
                    int num = orderOfBall.front() - (v[i].first % n);
                    int index2 = num;
                    if(num < 0) {
                        index2 = n + num;
                    } else if(num == 0) {
                        cout << "Goes inside" << "\n";
                        index2 = n;
                    }

                    if(index != index2) orderOfBall.push(index2);
                    cout << "Index: " << index << "\n";
                    cout << "Index2: " << index2 << "\n";
                    orderOfBall.pop();
                    listBall--;
                }
            }
            
            listBall = orderOfBall.size();
        }

        cout << listBall << "\n";
        vector<int> answer(orderOfBall.size());
        for(int i = 0; i < answer.size(); i++) {
            answer[i] = orderOfBall.front();
            orderOfBall.pop();
        }

        sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }

        cout << "\n";
    }
}