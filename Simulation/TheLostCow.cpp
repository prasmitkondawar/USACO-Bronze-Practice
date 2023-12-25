#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    // For getting input from input.txt file
   freopen("lostcow.in", "r", stdin);
    // Printing the Output to output.txt file
   freopen("lostcow.out", "w", stdout);
    int x, y;
    cin >> x >> y;

    int totDis = 0;
    int dis = 1;
    int sign = 1;
    int xi = x;
    while((!(y >= x && y <= xi) && !(y <= x && y >= xi)) && (xi != y)) {
        int xf = x + (dis * sign);
        dis *= 2;
        sign *= -1;
        totDis += abs(xf - xi);
        xi = xf;
    }
    
    if(xi != y) {
        totDis -= abs(xi - y);
    }

    cout << totDis << "\n";
}