#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int x, y;
    cin >> x >> y;

    int totDis = 0;
    int dis = 1;
    int sign = 1;
    while(x != y) {
        int xf = x + (dis * sign);
        dis++;
        sign *= -1;
        totDis += abs(xf - x);
        x = xf;
    }
}