// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // For getting input from input.txt file
    freopen("pails.in", "r", stdin);
    // Printing the Output to output.txt file
    freopen("pails.out", "w", stdout);
	int x, y, m;
	cin >> x >> y >> m;
	int combos = m / y;
	int counterx = 0;
	int countery = combos;
	int ans = 0;
	bool found = false;
	for(int i = 0; i <= combos; i++) {
		int dif1 = m - (countery * y);
		counterx = dif1 / x;
		int tot = (countery * y) + (counterx * x);
		int difference = m - tot;
		if(difference == 0) {
			cout << tot << "\n";
			found = true;
			break;
		} else if(tot > ans) {
			ans = tot;
		}

		countery--;
	}

	if(!found) cout << ans << "\n";
}
