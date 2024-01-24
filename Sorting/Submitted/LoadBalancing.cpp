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
	vector<int> xList(n);
	vector<int> yList(n);

	for(int i = 0; i < n; i++) {
		cin >> xList[i];
		cin >> yList[i];
	}

	sort(xList.begin(), xList.end());
	sort(yList.begin(), yList.end());

	int ans = 1000000;
	for(int vert = 0; vert < n; vert++) {
		int x = xList[vert] - 1;
		int q1, q2, q3, q4;
		for(int hor = 0; hor < n; hor++) {
			int y = yList[hor] - 1;
			int q1 = (n - vert) - (n - hor);
			int q2 = (n - vert) - hor;
			int q3 = (vert) - (n - hor);
			int q4 = (vert) - (hor);
			//cout << "q1: " << q1 << ", " << "q2: " << q2 << ", " << "q3: " << q3 << ", " "q4: " << q4 << "\n";
			ans = min(ans, max(max(q1, q2), max(q3, q4)) + 1);
		}
	}
	
	cout << ans << "\n";
}