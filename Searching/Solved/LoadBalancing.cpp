// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// For getting input from input.txt file
    freopen("balancing.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("balancing.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<long> xList(n);
	vector<long> yList(n);
	vector<pair<long, long>> list(n);

	for(int i = 0; i < n; i++) {
		cin >> list[i].first >> list[i].second;
		xList[i] = list[i].first;
		yList[i] = list[i].second;

	}

	sort(xList.begin(), xList.end());
	sort(yList.begin(), yList.end());

	int ans = 1000000;
	for(int vert = 0; vert < n - 1; vert++) {
		int x = xList[vert] + 1;
		if(x != xList[vert + 1] + 1) {
			for(int hor = 0; hor < n - 1; hor++) {
				int y = yList[hor] + 1;
				int q1 = 0;
				int q2 = 0;
				int q3 = 0;
				int q4 = 0;
				if(y != yList[hor + 1] + 1) {
					//if(x == 6 && y == 4) cout << "true" << "\n";
					for(int i = 0; i < n; i++) {
						if(list[i].first > x && list[i].second > y) q1++;
						else if(list[i].first > x && list[i].second < y) q4++;
						else if(list[i].first < x && list[i].second > y) q2++;
						else q3++;

					}
					
					//if(x == 6 && y == 4) cout << "q1: " << q1 << ", " << "q2: " << q2 << ", " << "q3: " << q3 << ", " "q4: " << q4 << "\n";
					ans = min(ans, max(max(q1, q2), max(q3, q4)));
				}
				//cout << "q1: " << q1 << ", " << "q2: " << q2 << ", " << "q3: " << q3 << ", " "q4: " << q4 << "\n";
			}
		}
	}
	
	cout << ans << "\n";
}